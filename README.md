
# 🚀 Edge-Optimized Distributed Perception Pipeline (ROS2 & C++)

A low-latency, distributed computer vision pipeline built with **ROS2 (Jazzy)** and **C++**.
This project demonstrates how real-time perception systems can be designed, tested, and validated **without direct dependency on physical edge hardware**.

---

## 🧠 Overview

Instead of relying on a monolithic script, this system adopts a **distributed microservice architecture** using ROS2’s Publisher/Subscriber model.

The pipeline is designed for:

* Autonomous systems
* Edge AI prototyping
* Real-time perception testing (SIL – Software-in-the-loop)

---

## 🏗️ System Architecture

The system consists of two independent ROS2 nodes:

### 📡 Sensor Node (Publisher)

* Reads video stream from a `.mp4` file
* Converts frames using `cv_bridge`
* Publishes frames to the ROS2 network via `sensor_msgs`

### 🧠 Perception Node (Subscriber)

* Subscribes to incoming image stream
* Applies **Canny Edge Detection (OpenCV)**
* Measures **end-to-end latency (network + processing)**

---

## ⚙️ Tech Stack

* **Framework:** ROS2 (Jazzy)
* **Language:** C++ (`rclcpp`)
* **Computer Vision:** OpenCV
* **ROS2 Interfaces:** `cv_bridge`, `sensor_msgs`

---

## 📈 Performance

The system processes video streams **frame-by-frame in real time**.

* ⏱️ **Latency:** 15 ms – 45 ms
* 🔄 Stable performance under continuous data streaming
* ☁️ Tested in **cloud-based environment (SIL)**

This demonstrates that distributed perception pipelines can operate efficiently **before deploying to edge devices (HIL)**.

---

## 🎯 Why This Matters

This project shows that:

* Real-time AI pipelines can be **prototyped in the cloud**
* Distributed architectures improve **modularity and fault tolerance**
* Systems can be validated **before hardware deployment**

---

## 🚀 Getting Started

### 1. Clone the Repository

```bash
cd ~/ros2_ws/src
git clone <your-repo-link>
```

### 2. Build the Package

```bash
cd ~/ros2_ws
colcon build
```

### 3. Source the Workspace

```bash
source install/setup.bash
```

### 4. Run the Nodes

**Terminal 1 – Sensor Node**

```bash
ros2 run vision_system sensor_node
```

**Terminal 2 – Perception Node**

```bash
ros2 run vision_system perception_node
```

---

## 📸 Demo

> The demo video includes:

* Real-time system execution
* Live latency measurements
* Bottleneck observations

---

## 🔮 Future Improvements

* Replace Canny with **Deep Learning-based models (YOLO / segmentation)**
* Deploy to **Raspberry Pi / Jetson (Edge Hardware)**
* Integrate **multi-sensor fusion**
* Optimize for **GPU acceleration**

---

## 🤝 Contributing

Feel free to fork, experiment, and improve the system.
Feedback and suggestions are always welcome!

---

## 📬 Contact

If you're interested in this project or working on similar systems, let's connect.

 
