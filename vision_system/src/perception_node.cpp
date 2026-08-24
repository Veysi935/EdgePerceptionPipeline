#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <cv_bridge/cv_bridge.hpp>
#include <opencv2/opencv.hpp>

class PerceptionNode : public rclcpp::Node {
public:
    PerceptionNode() : Node("perception_node") {
        subscription_ = this->create_subscription<sensor_msgs::msg::Image>(
            "camera_stream", 10, std::bind(&PerceptionNode::topic_callback, this, std::placeholders::_1));
    }
private:
    void topic_callback(const sensor_msgs::msg::Image::SharedPtr msg) {
        // Zaman hesaplamasi (C++ ROS2 standardina guncellendi)
        auto start_time = rclcpp::Time(msg->header.stamp);
        auto end_time = this->now();
        double latency = (end_time.nanoseconds() - start_time.nanoseconds()) / 1000000.0;
        if (latency < 0) latency += 1000.0; 

        // ROS2 mesajini OpenCV formatina geri cevir
        cv::Mat frame = cv_bridge::toCvShare(msg, "bgr8")->image;
        cv::Mat edges;
        
        // Otonom araclarda kullanilan Kenar Tespiti algoritmasi
        cv::Canny(frame, edges, 100, 200);

        // Kodu bulutta görsellestirmek icin resmi surekli uzerine yazarak kaydediyoruz
        cv::imwrite("islenmis_kare.jpg", edges);
        
        RCLCPP_INFO(this->get_logger(), "[ABONE] Canny uygulandi. Ag Gecikmesi: %.2f ms", latency);
    }
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscription_;
};

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PerceptionNode>());
    rclcpp::shutdown();
    return 0;
}