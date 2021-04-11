//#include <movingAvg.h>
#include "test.h"

		int m_interval;     // number of data points for the moving average
    int m_nbrReadings;  // number of readings
    long m_sum;         // sum of the m_readings array
    int m_next;         // index to the next reading
    int m_readings[10]={0}; 
		

// initialize - allocate the interval array
void begin(int _m_interval)
{
  // m_readings = m_interval;
}

		int getCount(void) {return m_nbrReadings;}
		int* getReadings(void) {return m_readings;}

// add a new reading and return the new moving average
int reading(int newReading)
{
    // add each new data point to the sum until the m_readings array is filled
    if (m_nbrReadings < m_interval)
    {
        ++m_nbrReadings;
        m_sum = m_sum + newReading;
    }
    // once the array is filled, subtract the oldest data point and add the new one
    else
    {
        m_sum = m_sum - m_readings[m_next] + newReading;
    }

    m_readings[m_next] = newReading;
    if (++m_next >= m_interval) m_next = 0;
    return (m_sum + m_nbrReadings / 2) / m_nbrReadings;
}

// just return the current moving average
int getAvg()
{
    return (m_sum + m_nbrReadings / 2) / m_nbrReadings;
}

// start the moving average over again
void reset()
{
    m_nbrReadings = 0;
    m_sum = 0;
    m_next = 0;
}
