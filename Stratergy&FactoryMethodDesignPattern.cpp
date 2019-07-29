#include <iostream>
#include <memory>
#include <utility> 
#include <string> 

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
            unique_ptr<ISpinBehavior> SpinType,
            unique_ptr<string> BowlingStyleName) {
                this->BowlingArm = move (BowlingArm);
                this->BowlingSpeed = move (BowlingSpeed);
                this->SpinType = move (SpinType);
                this->BowlingStyleName = move (BowlingStyleName);
            }
    void DisplayDetails () {
        cout << "*********** " << this->BowlingStyleName->c_str() <<" ************" << endl;
        this->BowlingArm->DisplayBowlingArm ();
        this->BowlingSpeed->DisplaySpeed ();
        this->SpinType->DisplaySpin ();
        cout << "*********************************************" << endl << endl;
    }
    private:
    unique_ptr<IBowlingArmBehavior> BowlingArm;
    unique_ptr<ISpeedBehavior> BowlingSpeed;
    unique_ptr<ISpinBehavior> SpinType;
    unique_ptr<string> BowlingStyleName;
};

class IBowlerFactory {
    public:
    virtual unique_ptr<Bowler> CreateBowler () = 0;
    protected:
    unique_ptr<IBowlingArmBehavior> BowlingArm;
    unique_ptr<ISpeedBehavior> BowlingSpeed;
    unique_ptr<ISpinBehavior> SpinType;
    unique_ptr<string> BowlingStyleName;
};

class RightArmFastBowler:public IBowlerFactory {
    public:
        unique_ptr<Bowler> CreateBowler () override {
            unique_ptr<Bowler> BowlerObject;
            BowlingArm.reset(new BowlingArmRight);
            BowlingSpeed.reset(new SpeedFast);
            SpinType.reset(new NoSpin);
            BowlingStyleName.reset(new string ("Right Arm Fast Bowler"));
            
            BowlerObject.reset (new Bowler(move(BowlingArm), 
            move(BowlingSpeed), 
            move(SpinType),
            move(BowlingStyleName)));
            
            return BowlerObject;
    }
};
class LeftArmFastBowler:public IBowlerFactory {
    public:
        unique_ptr<Bowler> CreateBowler () override {
            unique_ptr<Bowler> BowlerObject;
            BowlingArm.reset(new BowlingArmLeft);
            BowlingSpeed.reset(new SpeedFast);
            SpinType.reset(new NoSpin);
            BowlingStyleName.reset(new string ("Left Arm Fast Bowler"));
            
            BowlerObject.reset (new Bowler(move(BowlingArm), 
            move(BowlingSpeed), 
            move(SpinType),
            move(BowlingStyleName)));
            
            return BowlerObject;
    }
};
class RightArmMediumBowler:public IBowlerFactory {
    public:
        unique_ptr<Bowler> CreateBowler () override {
            unique_ptr<Bowler> BowlerObject;
            BowlingArm.reset(new BowlingArmRight);
            BowlingSpeed.reset(new SpeedMedium);
            SpinType.reset(new NoSpin);
            BowlingStyleName.reset(new string ("Right Arm Medium Fast"));
            
            BowlerObject.reset (new Bowler(move(BowlingArm), 
            move(BowlingSpeed), 
            move(SpinType),
            move(BowlingStyleName)));
            
            return BowlerObject;
    }
};
class LeftArmMediumBowler:public IBowlerFactory {
    public:
        unique_ptr<Bowler> CreateBowler () override {
            unique_ptr<Bowler> BowlerObject;
            BowlingArm.reset(new BowlingArmLeft);
            BowlingSpeed.reset(new SpeedMedium);
            SpinType.reset(new NoSpin);
            BowlingStyleName.reset(new string ("Left Arm Medium Fast"));
            
            BowlerObject.reset (new Bowler(move(BowlingArm), 
            move(BowlingSpeed), 
            move(SpinType),
            move(BowlingStyleName)));
            
            return BowlerObject;
    }
};
class OffSpinBowler:public IBowlerFactory {
    public:
        unique_ptr<Bowler> CreateBowler () override {
            unique_ptr<Bowler> BowlerObject;
            BowlingArm.reset(new BowlingArmRight);
            BowlingSpeed.reset(new SpeedSlow);
            SpinType.reset(new FingerSpin);
            BowlingStyleName.reset(new string ("Off Spiner"));
            
            BowlerObject.reset (new Bowler(move(BowlingArm), 
            move(BowlingSpeed), 
            move(SpinType),
            move(BowlingStyleName)));
            
            return BowlerObject;
    }
};
class LegSpinBowler:public IBowlerFactory {
    public:
        unique_ptr<Bowler> CreateBowler () override {
            unique_ptr<Bowler> BowlerObject;
            BowlingArm.reset(new BowlingArmRight);
            BowlingSpeed.reset(new SpeedSlow);
            SpinType.reset(new WristSpin);
            BowlingStyleName.reset(new string ("Leg Spiner"));
            
            BowlerObject.reset (new Bowler(move(BowlingArm), 
            move(BowlingSpeed), 
            move(SpinType),
            move(BowlingStyleName)));
            
            return BowlerObject;
    }
};
class LeftArmOrthodoxBowler:public IBowlerFactory {
    public:
        unique_ptr<Bowler> CreateBowler () override {
            unique_ptr<Bowler> BowlerObject;
            BowlingArm.reset(new BowlingArmLeft);
            BowlingSpeed.reset(new SpeedSlow);
            SpinType.reset(new FingerSpin);
            BowlingStyleName.reset(new string ("Left Arm Orthodox"));
            
            BowlerObject.reset (new Bowler(move(BowlingArm), 
            move(BowlingSpeed), 
            move(SpinType),
            move(BowlingStyleName)));
            
            return BowlerObject;
    }
};
class ChinaManBowler:public IBowlerFactory {
    public:
        unique_ptr<Bowler> CreateBowler () override {
            unique_ptr<Bowler> BowlerObject;
            BowlingArm.reset(new BowlingArmLeft);
            BowlingSpeed.reset(new SpeedSlow);
            SpinType.reset(new WristSpin);
            BowlingStyleName.reset(new string ("Left Arm China Man bowler"));
            
            BowlerObject.reset (new Bowler(move(BowlingArm), 
            move(BowlingSpeed), 
            move(SpinType),
            move(BowlingStyleName)));
            
            return BowlerObject;
    }
};
    
int main() {
    unique_ptr<IBowlerFactory> RightArmFastBowlerFactory;
    unique_ptr<IBowlerFactory> LeftArmFastBowlerFactory;
    unique_ptr<IBowlerFactory> RightArmMediumBowlerFactory;
    unique_ptr<IBowlerFactory> LeftArmMediumBowlerFactory;
    unique_ptr<IBowlerFactory> OffSpinBowlerFactory;
    unique_ptr<IBowlerFactory> LegSpinBowlerFactory;
    unique_ptr<IBowlerFactory> LeftArmOrthodoxBowlerFactory;
    unique_ptr<IBowlerFactory> ChinaManBowlerFactory;

    unique_ptr<Bowler> RightArmFast;
    unique_ptr<Bowler> LeftArmFast;
    unique_ptr<Bowler> RightArmMedium;
    unique_ptr<Bowler> LeftArmMedium;
    unique_ptr<Bowler> OffSpiner;
    unique_ptr<Bowler> LegSpiner;
    unique_ptr<Bowler> LeftArmOrthodox;
    unique_ptr<Bowler> ChinaMan;
    
    RightArmFastBowlerFactory.reset (new RightArmFastBowler);
    LeftArmFastBowlerFactory.reset (new LeftArmFastBowler);
    RightArmMediumBowlerFactory.reset (new RightArmMediumBowler);
    LeftArmMediumBowlerFactory.reset (new LeftArmMediumBowler);
    OffSpinBowlerFactory.reset (new OffSpinBowler);
    LegSpinBowlerFactory.reset (new LegSpinBowler);
    LeftArmOrthodoxBowlerFactory.reset (new LeftArmOrthodoxBowler);
    ChinaManBowlerFactory.reset (new ChinaManBowler);
    
    RightArmFast = move(RightArmFastBowlerFactory->CreateBowler ());
    LeftArmFast = move(LeftArmFastBowlerFactory->CreateBowler ());
    RightArmMedium = move(RightArmMediumBowlerFactory->CreateBowler ());
    LeftArmMedium = move(LeftArmMediumBowlerFactory->CreateBowler ());
    OffSpiner = move(OffSpinBowlerFactory->CreateBowler ());
    LegSpiner = move(LegSpinBowlerFactory->CreateBowler ());
    LeftArmOrthodox = move(LeftArmOrthodoxBowlerFactory->CreateBowler ());
    ChinaMan = move(ChinaManBowlerFactory->CreateBowler ());
    
    RightArmFast->DisplayDetails ();
    LeftArmFast->DisplayDetails ();
    RightArmMedium->DisplayDetails ();
    LeftArmMedium->DisplayDetails ();
    OffSpiner->DisplayDetails ();
    LegSpiner->DisplayDetails ();
    LeftArmOrthodox->DisplayDetails ();
    ChinaMan->DisplayDetails ();
    
    return 0;
}