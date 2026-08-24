#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <cv_bridge/cv_bridge.hpp>
#include <opencv2/opencv.hpp>
#include <chrono>

using namespace std::chrono_literals;

class SensorNode : public rclcpp::Node {
public:
    SensorNode() : Node("sensor_node") {
        publisher_ = this->create_publisher<sensor_msgs::msg::Image>("camera_stream", 10);
        // Yüklediğin videoyu açıyoruz
        cap_.open("src/vision_system/test_video.mp4");
        if (!cap_.isOpened()) {
            RCLCPP_ERROR(this->get_logger(), "HATA: Video dosyasi bulunamadi veya acilamadi!");
        }
        timer_ = this->create_wall_timer(33ms, std::bind(&SensorNode::timer_callback, this));
    }
private:
    void timer_callback() {
        cv::Mat frame;
        cap_ >> frame;
        if (frame.empty()) {
            cap_.set(cv::CAP_PROP_POS_FRAMES, 0); // Video bitince basa sar
            return;
        }
        // OpenCV karesini ROS2 mesajina cevir
        auto msg = cv_bridge::CvImage(std_msgs::msg::Header(), "bgr8", frame).toImageMsg();
        msg->header.stamp = this->now();
        publisher_->publish(*msg);
        RCLCPP_INFO(this->get_logger(), "[YAYINCI] Gercek video karesi aga pompalandi.");
    }
    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    cv::VideoCapture cap_;
};

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SensorNode>());
    rclcpp::shutdown();
    return 0;
}