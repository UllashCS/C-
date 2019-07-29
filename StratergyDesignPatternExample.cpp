#include <iostream>
#include <memory>
#include <utility> 

using namespace std;

class IBowlingArmBehavior {
    public:
    virtual void DisplayBowlingArm () = 0;
};
class ISpeedBehavior {
    public:
    virtual void DisplaySpeed () = 0;
};
class ISpinBehavior {
    public:
    virtual void DisplaySpin () = 0;
};

class BowlingArmLeft:public IBowlingArmBehavior {
    public:
    void DisplayBowlingArm () override final{
        cout << "Bowling Arm : Left" <<endl;
    }
};
class BowlingArmRight:public IBowlingArmBehavior {
    public:
    void DisplayBowlingArm () override final{
        cout << "Bowling Arm : Right"<<endl;
    }
};

class SpeedSlow:public ISpeedBehavior {
    public:
    void DisplaySpeed () override final {
        cout << "Bowling Speed : Slow"<<endl;
    }
};
class SpeedMedium:public ISpeedBehavior {
    public:
    void DisplaySpeed () override final {
        cout << "Bowling Speed : Medium"<<endl;
    }
};
class SpeedFast:public ISpeedBehavior {
    public:
    void DisplaySpeed () override final {
        cout << "Bowling Speed : Fast"<<endl;
    }
};

class WristSpin:public ISpinBehavior {
    public:
    void DisplaySpin () override final {
        cout << "Spin Type : Wrist Spin" <<endl;
    }
};
class FingerSpin:public ISpinBehavior {
    public:
    void DisplaySpin () override final {
        cout << "Spin Type : Finger Spin" <<endl;
    }
};
class NoSpin:public ISpinBehavior {
    public:
    void DisplaySpin () override final {
        cout << "Spin Type : No Spin" <<endl;
    }
};

class Bowler {
    public:
    Bowler (unique_ptr<IBowlingArmBehavior> BowlingArm, 
            unique_ptr<ISpeedBehavior> BowlingSpeed, 
            unique_ptr<ISpinBehavior> SpinType) {
                this->BowlingArm = move (BowlingArm);
                this->BowlingSpeed = move (BowlingSpeed);
                this->SpinType = move (SpinType);
            }
    void DisplayDetails () {
        cout << "*********** Details ************" << endl;
        this->BowlingArm->DisplayBowlingArm ();
        this->BowlingSpeed->DisplaySpeed ();
        this->SpinType->DisplaySpin ();
        cout << "********************************" << endl << endl;
    }
    private:
    unique_ptr<IBowlingArmBehavior> BowlingArm;
    unique_ptr<ISpeedBehavior> BowlingSpeed;
    unique_ptr<ISpinBehavior> SpinType;
};

int main() {
    unique_ptr<IBowlingArmBehavior> BowlingArm;
    unique_ptr<ISpeedBehavior> BowlingSpeed;
    unique_ptr<ISpinBehavior> SpinType;
    unique_ptr<Bowler> RightArmFastBowler;
    unique_ptr<Bowler> LeftArmFastBowler;
    unique_ptr<Bowler> RightArmMediumBowler;
    unique_ptr<Bowler> LeftArmMediumBowler;
    unique_ptr<Bowler> OffSpinBowler;
    unique_ptr<Bowler> LegSpinBowler;
    unique_ptr<Bowler> LeftArmOrthodoxBowler;
    unique_ptr<Bowler> ChinaManBowler;
    
    BowlingArm.reset(new BowlingArmRight);
    BowlingSpeed.reset(new SpeedFast);
    SpinType.reset(new NoSpin);
    
    RightArmFastBowler.reset(new Bowler(move(BowlingArm), 
                            move(BowlingSpeed), 
                            move(SpinType)));
    
    BowlingArm.reset(new BowlingArmLeft);
    BowlingSpeed.reset(new SpeedFast);
    SpinType.reset(new NoSpin);
    
    LeftArmFastBowler.reset(new Bowler(move(BowlingArm), 
                            move(BowlingSpeed), 
                            move(SpinType)));
    
    BowlingArm.reset(new BowlingArmRight);
    BowlingSpeed.reset(new SpeedMedium);
    SpinType.reset(new NoSpin);
    
    RightArmMediumBowler.reset(new Bowler(move(BowlingArm), 
                            move(BowlingSpeed), 
                            move(SpinType)));
                            
    BowlingArm.reset(new BowlingArmLeft);
    BowlingSpeed.reset(new SpeedMedium);
    SpinType.reset(new NoSpin);
    
    LeftArmMediumBowler.reset(new Bowler(move(BowlingArm), 
                            move(BowlingSpeed), 
                            move(SpinType)));

    BowlingArm.reset(new BowlingArmRight);
    BowlingSpeed.reset(new SpeedSlow);
    SpinType.reset(new FingerSpin);
    
    OffSpinBowler.reset(new Bowler(move(BowlingArm), 
                            move(BowlingSpeed), 
                            move(SpinType)));
    
    BowlingArm.reset(new BowlingArmRight);
    BowlingSpeed.reset(new SpeedSlow);
    SpinType.reset(new WristSpin);
    
    LegSpinBowler.reset(new Bowler(move(BowlingArm), 
                            move(BowlingSpeed), 
                            move(SpinType)));
                            
    BowlingArm.reset(new BowlingArmLeft);
    BowlingSpeed.reset(new SpeedSlow);
    SpinType.reset(new FingerSpin);
    
    LeftArmOrthodoxBowler.reset(new Bowler(move(BowlingArm), 
                            move(BowlingSpeed), 
                            move(SpinType)));
    
    BowlingArm.reset(new BowlingArmLeft);
    BowlingSpeed.reset(new SpeedSlow);
    SpinType.reset(new WristSpin);
    
    ChinaManBowler.reset(new Bowler(move(BowlingArm), 
                            move(BowlingSpeed), 
                            move(SpinType)));
    
    RightArmFastBowler->DisplayDetails ();
    LeftArmFastBowler->DisplayDetails ();
    RightArmMediumBowler->DisplayDetails ();
    LeftArmMediumBowler->DisplayDetails ();
    OffSpinBowler->DisplayDetails ();
    LegSpinBowler->DisplayDetails ();
    LeftArmOrthodoxBowler->DisplayDetails ();
    ChinaManBowler->DisplayDetails ();
    
    return 0;
}