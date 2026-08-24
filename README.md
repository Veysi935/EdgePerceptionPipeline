
# 🚀 Edge-Optimized Distributed Perception Pipeline (ROS2 & C++)

This project implements a low-latency, distributed computer vision pipeline using **ROS2 (Jazzy)** and **C++**. Designed for edge computing, wearable devices, and mobile AI applications, the architecture splits the workload into independent microservices to ensure real-time performance and fault tolerance.

## 🧠 System Architecture

Instead of a monolithic script, the system is built on a Publisher/Subscriber model:
*   **Sensor Node (Publisher):** Reads a continuous video stream (`.mp4`) and publishes the raw frames to the ROS2 network using `cv_bridge` and `sensor_msgs`.
*   **Perception Node (Subscriber):** Instantly captures the streaming frames from the network, applies industrial computer vision algorithms (Canny Edge Detection), and calculates the exact network + processing latency.

## 🛠️ Tech Stack
*   **Framework:** ROS2 (Jazzy)
*   **Language:** C++ (rclcpp)
*   **Computer Vision:** OpenCV
*   **Integration:** cv_bridge, sensor_msgs

## 📈 Performance
The distributed architecture processes high-resolution video streams frame-by-frame with a total network and inference latency dynamically ranging between **15 ms and 45 ms**, proving its viability for real-time autonomous decision-making in hardware-in-the-loop (HIL) environments.

## 🚀 How to Run

1. Clone the repository into your ROS2 workspace (`~/ros2_ws/src/`).
2. Build the package:
   ```bash
   colcon build
