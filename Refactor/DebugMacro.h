/**
 * @brief Defines some macros for debugging output
 * 
 */
#define DEBUG

#ifdef DEBUG
    #define DEBUG_OUT(x) (std::cout << x << std::endl);
#else 
    #define DEBUG_OUT(x) do{}while(0);
#endif