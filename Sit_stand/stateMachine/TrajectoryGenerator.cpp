#include sitStand.h
#include Robot.h

class TrajectoryGenerator{
    public: 
        virtual double generateTrajectory() (int jointInd, int desiredIndex, Robot *rob)
}

class SittingTraj : public TrajectoryGenerator {
    public:
        SittingTraj(){};
        virtual double generateTrajectory() (int jointInd, int desiredIndex, Robot *rob)
        { 
            int jointID = rob->joints[jointInd].getId();
            double desPos = 0;
            
            if (desiredIndex >= LENGTH_TRAJ){
                desiredIndex = LENGTH_TRAJ -1;
            }
            
            if (jointID == LEFT_KNEE)
            {
                desPos= stationarySittingKneeTraj[desiredIndex];
            }
            else if(jointID == RIGHT_KNEE)
            {
                desPos= stationarySittingKneeTraj[desiredIndex];
            }
            else if (jointID == LEFT_HIP)
            {
                desPos= stationarySittingHipTraj[desiredIndex];
            }
            else if (jointID == RIGHT_HIP)
            {
                desPos= stationarySittingHipTraj[desiredIndex];
            }
            return desPos;
        }
};