/* Student.h - Header file for Students at MiraCosta (child of PersonAtMCC)
 * Author:     Ben Foltz
 * Module:     7
 * Project:    Lab, Part 1
 * Description:
 *
 *    Child of PersonAtMCC
 *
 *    Instance members:
 *       major (string)
 *       credits_received (int)
 *       applied_to_4_year (bool)
 *       is_veteran (bool)
 *
 *    Functions:
 *       full constructor
 *       getters and setters for all instance members
 *       showInfo
 */

#ifndef STUDENT_H
#define STUDENT_H

#include "PersonAtMCC.h"
using namespace std ;

class Student: public PersonAtMCC {

    private :
        string major ;
        int credits_received ;
        bool applied_to_4_year ;
        bool is_veteran ;

    public :
        Student(long, string, string, string, string, int, bool, bool) ;    // full constructor

        string getMajor() ;                        // all getters and setters
        void setMajor(string) ;
        int getCreditsReceived() ;
        void setCreditsReceived(int) ;
        bool getAppliedTo4Year() ;
        void setAppliedTo4Year(bool) ;
        bool getIsVeteran() ;
        void setIsVeteran(bool) ;

        void showInfo() ;
} ;

#endif
