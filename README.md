# water-bucket-project
Software design for Electric water bucket

function specifications-->

int manual();-- This function is for manual mode.

int automatic();-- This one is for automatic mode.

int changemode();-- It switch the mode between automatic and manual.

int manual_dial(int dial);-- This one is use to set the current in manual mode.

int changetemp();--It include code to change the temperature.

int change_temp_by_dial();--this is used to change temperature through dial by rotating.

int change_temp_by_mobileapp();--this is used to set or clear temperature through Mobile app.

int temp_drop();-- This function continue reduces the temperature if temp greater than 22 degree celsius.

void *real_thread_temp(float *m_curr)-- added thread to show real time temperature.
