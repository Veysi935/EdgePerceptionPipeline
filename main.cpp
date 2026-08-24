#include <opencv2/opencv.hpp>
#include <iostream>
#include <chrono>

using namespace cv;
using namespace std;
using namespace std::chrono;

int main() {
    cout << "[SISTEM] Low-Latency Perception Pipeline Baslatiliyor..." << endl;
    
    // 640x480 boyutlarında sahte bir kamera karesi (Mock Data) oluşturuyoruz
    Mat frame(480, 640, CV_8UC3, Scalar(0, 0, 0)); 
    int frames = 0;
    auto start_time = high_resolution_clock::now();

    cout << "[SISTEM] Sensor verisi isleniyor (Stres Testi)..." << endl;

    // Sistemi test etmek için 2000 karelik kesintisiz bir döngü
    for(int i = 0; i < 2000; i++) {
        
        // Sensörden gelen veriyi işliyormuşuz gibi Gaussian bulanıklaştırma filtresi uyguluyoruz
        GaussianBlur(frame, frame, Size(7, 7), 1.5, 1.5);
        
        frames++;
        auto current_time = high_resolution_clock::now();
        double elapsed = duration_cast<milliseconds>(current_time - start_time).count();

        // Her saniyede bir metrikleri ekrana bas
        if (elapsed >= 1000.0) {
            cout << "[METRIK] FPS: " << frames 
                 << " | Kare Basina Gecikme (Latency): " << 1000.0/frames << " ms" << endl;
            frames = 0;
            start_time = high_resolution_clock::now();
        }
    }
    
    cout << "[SISTEM] Pipeline testi basariyla tamamlandi." << endl;
    return 0;
}