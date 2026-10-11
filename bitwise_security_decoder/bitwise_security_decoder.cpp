//Bitwise security decoder system

#include <iostream>
using namespace std;
int main()
{
long roomSignal;
cout<<"Enter roomSignal integer:";  //INPUT
if (!(cin >> roomSignal))
{
    cout << "Invalid input." << endl;
    return 0;
}

//SENSORS Masking
int active_sensor, main_door,window, motion_detection, emergency_button;
active_sensor=roomSignal & 15;
main_door=roomSignal & 1;
window=(roomSignal>>1) & 1;
motion_detection=(roomSignal>>2) & 1;
emergency_button=(roomSignal>>3) & 1;

//BITS 4-13 Masking
int zone_number=(roomSignal>>4) & 7;
int access_level=(roomSignal>>7) & 3;
int maintenance=(roomSignal>>13) & 1;
int encoded_incidentCode=(roomSignal>>9) & 15;
int decoded_code=encoded_incidentCode ^ 5;

//EXTRACTION
if (emergency_button==1)
{
 cout << "Security Report: EMERGENCY" << endl;
}
else if (maintenance==1)
{
 cout << "Security Report: MAINTENANCE" << endl;
}
else if ((main_door==1 || window==1) && access_level==0)
{
 cout << "Security Report: UNAUTHORIZED ACCESS" << endl;
}
else if (motion_detection==1 && decoded_code>=9)
{
 cout << "Security Report: SECURITY ALERT" << endl;
}
else if (active_sensor==0 && decoded_code==0)
{
 cout << "Security Report: ROOM SECURE" << endl;
}
else
{
 cout << "Security Report: MONITOR REQUIRED" << endl;
}
return 0;
}
