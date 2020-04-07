/**
 * The <code>Joint</code> class is a abstract class which represents a joint in a
 * <code>Robot</code> objec. This class can be used to represent all types of joints,
 * including actuated, non-actuated, revolute, prismatic, etc.
 * 
 *
 * Version 0.1
 * Date: 07/04/2020
 */

class Joint
{
private:
/**
 * An identifier for this joint. Note that this identifier is designed to be unique, 
 * but this is not managed by the joint class. 
 */
    const int id;
/**
 * The current state of the joint (i.e. the value), to be returned in SI units.
 */
    double q;
/**
 * The allowable limits of the joint. This should represent the theoretical limits
 * of the joint. Should these be exceeded, an error should be thrown. 
 */
    const double qMin, qMax;

public:
/**
 * Default <code>Joint</code> constructor. Note that it requires an ID, and minimum
 * and maximum joint limits. These limits will be used to check for errors. 
 */
    Joint(int jointID, double jointMin, double jointMax);
/**
 * Return the ID of the joint
 */
    int getId();
/**
 * Returns the value of the joint (e.g. Angle, length, depending on joint type)
 * 
 * NOTE: This returns only a single double value. Implementations of this joint may
 * choose to include other methods to return other states of the joint. 
 */
    double getQ();
/**
 * Updates the value of the joint. This will read the value from hardware, and
 * update the software's current representation of the value
 */
    virtual bool updateValue();
};