#include <chrono>
#include <iostream>
#include <cmath>

int main()
{
    int i, j;
    std::chrono::system_clock::time_point StartTime = std::chrono::system_clock::now();

   std::cout << "Hi I'm sewon ";
   for (i = 0; i < 9000; i++) {
       for (j = 0; j < 9000; j++)
                   std::sqrt(231.476L);
   }
  
    std::chrono::system_clock::time_point EndTime = std::chrono::system_clock::now();
    std::chrono::duration<double> DefaultSec = EndTime - StartTime;

    std::chrono::nanoseconds nano = EndTime - StartTime;
    std::chrono::microseconds micro = std::chrono::duration_cast<std::chrono::microseconds>(EndTime - StartTime);

    std::cout << "경과시간 : " << nano.count() << " nanoseconds" << std::endl;
    std::cout << "경과시간 : " << micro.count() << " microseconds" << std::endl;

    return 0;

}