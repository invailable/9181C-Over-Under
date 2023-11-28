/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\alex_                                            */
/*    Created:      Mon Aug 14 2023                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// FrontLeft            motor         18              
// FrontRight           motor         3               
// BackLeft             motor         20              
// BackRight            motor         1               
// Controller1          controller                    
// Flap1                digital_out   A               
// Flap2                digital_out   B               
// Catapult             motor         17              
// Intake               motor         7               
// Rotation             rotation      10              
// MiddleLeft           motor         19              
// MiddleRight          motor         2               
// Inertial1            inertial      4               
// ---- END VEXCODE CONFIGURED DEVICES ----


#include "vex.h"
#include <string.h>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;
using namespace vex; 
int go;
int rotate;
int count = 0;
string wing1 = "";
string wing2 = "";
//498100498100498100499900499900499900499900499900499900499900499900499900499900499900499900499900499900499900499900499900499900499900499900499900499900499900499900499900499900499900499900499900499900499900499900499900499900499900499900498900494900494900494900494900494900494900494900494900494900494900497000497000497000498700499400499500499500499200499200499200494900494900494900494900494900494900494900494900494900494900484900484900484900454900454900424900424900424900424900414900424900424900424900424900424900414900414900404900404900404900404900404900404900404900314900314900314900314900314900314900314900264900264900264900264900264900264900264900264900264900264900264900264900264900264900274900264900264900264900264900264900264900264900274900274900264900264900264900264900274900274900264900264900264900264900274900274900264900264900264900264900264900264900264900264900264900264900264900264900264900264900264900264900274900274900274900274900264900264900264900264900264900264900264900274900264900264900264900274900274900274900264900264900264900264900264900264900264900264900264900274900274900264900264900264900264900264900264900264900264900264900264900264900264900264900264900264900264900274900274900264900264900264900264600264600264600264400274400264300264000263600263600263400263400263400263500273500273500263700263700273700273700273700263700263900264200264200264200264900264900264900264900264900264900264900264900264900264900254900234900204900204900164900084900004900004900004900003900001000001000001000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000004900004900004900004900004900004900004900004900004900004900004900004900004900004900004900004900004900064900994900994900994900994900994900994900994900994900994900994900994900994900994900994900994900994900994900994900754900494200233700003500003500003500004700004700004900004900004900004900004600004200003400003400000800000800000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000004900004900004900004900974900994900994900994900994900994900994900994900994900994900994900994900994900994900994900994900994900994900994900994900494900494900004900004900004900004900004900004900004900004900004900004900004900002300002300000000000000000000000000000000000000000900000900004900004900004900004900004900004900004900004900004900494900494900994900994900994900994900994900994900994900994900994900994900994400994200994200994200994200994900994800994100992300990800990800990000990000900000490000490000490000490000490000490000490000490000490000490000490000490000490000490000490000490000490000490000490000490000490000490000495100495100494900494900494900494900494900494900494900494900494900494900494900494900494900495300495900496400497300497300497700497700497800497800496100496100464900454900454900454900444900444900434900434900434900404900404900354900354900354900314900314900304900304900314900284900284900264400263700263700263400263200263200263600264300254500254900254900254900234900234900234900224900224900224900224900224900224900234900234900235000235300235300235300235300235300235200235100225100225100225100234900224900224900234900234900224900234900234900234900235400235400236200236800236800226900226900226900236900226900226900226900236900226900226900236900236900226900236900226900226900237000227400227400227700237800237800237800237800317700497700497700497700497700497700497700497700497800497800497800497700497700497700497700497800497800497800497800497800497800497800497800497800497800497800497800497800497800497800497800497800497800497400497400494900494900494900494910494910494911494911494911494911494911494911494911494911494811494811494811492611492611494011494011494911494911464911344911344911004911004911004911004911004911004911004911004911004911004911004911004911004911004911004911004911004911004911004911004911004911004911004911004911004911004911004911004911004911004911004911004911994911994911994911994911994911994911994911994911994911994911994911994911994911994911994911994911994911994911994911994911994911994911994911994911994911994911994911994911994911994900494900494900494900494900495000495900496100496800496900496900497700497900497900497900497800497800497800496800496400495900495300494900494900484900464900444900394900394900314900254600204200163800163800163800093500013300003200003200003100003100003100003100003100002300001100001100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000004900004900004900004900004900004900004900004900004900004900004900004900774900774900994900994900994900994900994900994900994900994900994900994900994900994900994900994900994900994900994900994900994900994900994900994900994900934400934400490700490000490000490000490000490000490000490000490000490000490000490000490000490000490000490000490000490000490000490000490000490000494900494900494900494900494900494900494900494900494900494900464900415400415400346400297300277700268200258300258300268000268000266400265310264911264911264911264911264911264911225911206711197111197111197111187211187211177011157211157211157611157611147511097311047011027211027211007311007211007311007911007911008611008411008411004911004911004911004911004911004911004911004911004911004911004911004911004911004911004911004911004911004911994911994911994911994911994911994911994911994911994911994911994911994911994911994911994911994911994911994911994911994911994911994911994900994900494900494900494900494900494900490000490000490000490000490000490000490000490000490000490000490000490000490000490000491300494900494900494900494900494900494900494900494900414900414900354900314900314900314900315000315100315100315400315400315500315500315500315500315600315600315600315600315700315800315800316300316300316300316400316400316400316400316200316000315900315800315800315800315800315900316000316000316000316100316200316200316200316200316200316200316200316200316200316200316200316300316300316300316300316400316400316400316400315700315400315100315100314900314900314900314900314900314900304900304900294900294900294900294900294900304900294900294900294900294900295300295300296800307600298100299100299100299800299900309900299900299900289900289900269900269900259900239900239900239900179900159900125400004900004900004900004900004900004900004900004900004900004900004900009900009900009900009900009900009900009900009900009900009900009900499900499900499900499900499900499900499900499900499900499900499900499900499900499900499900499900499900499900499900498300494900494900494900494900494900494900494900494900499800499900499900499900499900499900499900499900499900499900499900499900499900499900499900499900499900074900074900004900004900004900004900004900004900004900004900005900005900007000007500007900008600009300009300009900009900009900009900009900009900009900009900009900009900009900009900006100004900004900004900004900004900004900004900004900004900004900004900004900504900504900994900994900994900994900994900994900994900994900994900994900994900994900994900994900994900994900994900994900994900994900994900994900994900724900684900664900664900544900514900514900494900494900124900004900004900004900004900004900004900004900004900004900004900004900004900004900004900004900004900004900004900004900004900004900004900004900004900004900004900004900004900004900004900004900004900994900994900994900994900994900994900994900994900994900994900994900944900494900494900494900494900494900494900494900494900494900494900494900494900494900494900494900494900494900494900494900494900494900494900494900494900494900494900004900004900004900004900004900004900004900004900004900004900724900994900994900994900994900994900994900994900994900994900994900994900994900994900994900994900994900994900994900994900494900494900494900494900494900494900494900494900

string save1 = "";
int correction1 = 0;
string save2 = "";
int correction2 = 270;
string save3 = "";

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here
void correct_orientation(int correction){
  while(Inertial1.angle() < correction - 2){
    FrontLeft.spin(vex::forward, 30, percent);
    FrontRight.spin(vex::reverse, 30, percent);
    MiddleLeft.spin(vex::forward, 30, percent);
    MiddleRight.spin(vex::reverse, 30, percent);
    BackLeft.spin(vex::forward, 30, percent);
    BackRight.spin(vex::reverse, 30, percent);
  }
  while(Inertial1.angle() > correction + 2){
    FrontLeft.spin(vex::reverse, 30, percent);
    FrontRight.spin(vex::forward, 30, percent);
    MiddleLeft.spin(vex::reverse, 30, percent);
    MiddleRight.spin(vex::forward, 30, percent);
    BackLeft.spin(vex::reverse, 30, percent);
    BackRight.spin(vex::forward, 30, percent);
  }
  FrontLeft.stop(brake);
  FrontRight.stop(brake);
  MiddleLeft.stop(brake);
  MiddleRight.stop(brake);
  BackLeft.stop(brake);
  BackRight.stop(brake);
}

void process_save(string save){
  while (1) {
    if(save.length() != 0){
      // spin chassis
      go = (save[0] - 48) * 10 + save[1] - 48;
      rotate = (save[2] - 48) * 10 + save[3] - 48;
      wing1 = save[4];
      wing2 = save[5];
      cout << go << endl;
      cout << rotate << endl;
      if(go != 49 || rotate != 49){
        if(rotate == 49){
          cout << "1" << endl;
          FrontLeft.spin(vex::forward, go * 2 - 99, percent);
          FrontRight.spin(vex::forward, go * 2 - 99, percent);
          MiddleLeft.spin(vex::forward, go * 2 - 99, percent);
          MiddleRight.spin(vex::forward, go * 2 - 99, percent);
          BackLeft.spin(vex::forward, go * 2 - 99, percent);
          BackRight.spin(vex::forward, go * 2 - 99, percent);
        }
        else{
          cout << "2" << endl;
          FrontLeft.spin(vex::forward, ((go * 2 - 99)) + ((rotate * 2 - 99) / 2.3), percent);
          FrontRight.spin(vex::forward, ((go * 2 - 99)) - ((rotate * 2 - 99) / 2.3), percent);
          MiddleRight.spin(vex::forward, ((go * 2 - 99)) - ((rotate * 2 - 99) / 2.3), percent);
          MiddleLeft.spin(vex::forward, ((go * 2 - 99)) + ((rotate * 2 - 99) / 2.3), percent);
          BackLeft.spin(vex::forward, ((go * 2 - 99)) + ((rotate * 2 - 99) / 2.3), percent);
          BackRight.spin(vex::forward, ((go * 2 - 99)) - ((rotate * 2 - 99) / 2.3), percent);
        }
      }
      else{
        cout << "3" << endl;
        FrontLeft.stop(brake);
        FrontRight.stop(brake);
        MiddleLeft.stop(brake);
        MiddleRight.stop(brake);
        BackLeft.stop(brake);
        BackRight.stop(brake);
      }
      if(wing1 == "1"){
        Flap1.set(true);
      }
      else{
        Flap1.set(false);
      }
      if(wing2 == "1"){
        Flap2.set(true);
      }
      else{
        Flap2.set(false);
      }
      //delete read parts of save file
      for (int i = 0; i < 6; i++) {
        save.erase(save.begin());
      }
    }
    else{
      FrontLeft.stop(brake);
      FrontRight.stop(brake);
      MiddleLeft.stop(brake);
      MiddleRight.stop(brake);
      BackLeft.stop(brake);
      BackRight.stop(brake);
      break;
    }
    wait(20, msec);
  }
}
/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  Catapult.setVelocity(90, percent);
  while(count > 0){
    count -= 1;
    Catapult.spinFor(vex::forward, 1, turns);
    wait(50, msec);
  }
  Catapult.spinFor(vex::forward, 0.5, turns);
  process_save(save1);
  correct_orientation(correction1);
  process_save(save2);
  correct_orientation(correction2);
  process_save(save3);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {

    wait(100, msec);
  }
}
