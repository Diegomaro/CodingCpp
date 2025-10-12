#include <chrono>
#include <iostream>

class Timer {
public:
	void start() {
		startTime = std::chrono::high_resolution_clock::now();
	}

	void stop() {
		endTime = std::chrono::high_resolution_clock::now();
	}

 	double elapsedMicroseconds() {
		return std::chrono::duration<double, std::micro>(endTime - startTime).count();
	}

	double elapsedMilliseconds() {
		return std::chrono::duration<double, std::milli>(endTime - startTime).count();
	}

	void report() {
		if(elapsedMilliseconds() < 1.0)
			std::cout << "Elapsed: " << elapsedMicroseconds() << " microsegundos (1e-6)\n";
		else {
			if(elapsedMilliseconds() >= 1000.0)
				std::cout << "Elapsed: " << elapsedMilliseconds()/1000.0 << " segundos\n";
			else
				std::cout << "Elapsed: " << elapsedMilliseconds() << " milisegundos (1e-3)\n";
		}
	}

private:
	std::chrono::high_resolution_clock::time_point startTime;
	std::chrono::high_resolution_clock::time_point endTime;
};
