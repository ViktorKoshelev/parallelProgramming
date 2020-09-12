#include <iostream>
#include <math.h>
#include <omp.h>

int main() {
  const double start = 0;
  const double end = 2*M_PI;
  const double delta = 0.125;

  const double length = end - start;

  double integral = 0;
  #pragma omp parallel
  {
    const int current = omp_get_thread_num();
    const int total = omp_get_num_threads();

    const double step_length = length / total;
    const double step_start = start + step_length * current;
    const double step_end = step_start + step_length;

    for (double i = step_start; i < step_end; i += delta) {
      integral += sin(i) * delta;
    }
    
  }
  std::cout << integral;
}