#ifndef MOVINGAVG_H_INCLUDED
#define MOVINGAVG_H_INCLUDED



        //movingAvg(int interval)
        //    : m_interval(interval), m_nbrReadings(0), m_sum(0), m_next(0) {}
   // pointer to the dynamically allocated interval array

		
    void begin(int m_interval);
    int reading(int newReading);
    int getAvg(void);
    //int getCount(void) {return m_nbrReadings;}
    void reset(void);
    //int* getReadings(void) {return m_readings;}




#endif
