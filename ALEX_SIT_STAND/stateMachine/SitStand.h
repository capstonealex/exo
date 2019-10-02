//
// Created by William Campbell on 2019-10-02.
//

#ifndef EXO_SITSTAND_H
#define EXO_SITSTAND_H


class SitStand {
public:
    SitStand(void);
    void init(void);
    void activate(void);
    void deactivate(void);
    void hwStateUpdate(void);
    void initRobot( Robot *rb );
    void bitFlip();

private:
    // Events
    EventObject(IsPressed) * isPressed;
    EventObject(IsCal) * isCal;
    EventObject(CalFail) * calFail;
    EventObject(IsStanding) * isStanding;
    EventObject(IsSitting) * isSitting;

    // States
    StateObject(Uncalibrated) * uncalibrated;
    StateObject(Calibrating) * calibrating;
    StateObject(Idle) * idle;
    StateObject(Siting) * siting;
    StateObject(StandingUp) * standingUp;
    StateObject(SittingDwn) * sittingDwn;

// Data
    double mark;
    int button;
    int bitFlipState;
    int arrayIndex;
};
#endif //EXO_SITSTAND_H
