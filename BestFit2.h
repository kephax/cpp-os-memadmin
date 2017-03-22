#pragma once
#ifndef	__BestFit2_h__
#define	__BestFit2_h__


#include "BestFit.h"

class	BestFit2 : public BestFit
{
public:

    explicit	// see: http://en.cppreference.com/w/cpp/language/explicit
    /// @param cflag	initial status of check-mode
    /// @param type		name of this algorithm (default=BestFit2)
    BestFit2(bool cflag=false, const char *type = "BestFit (eager)")
        : BestFit(cflag, type) {}

    /// The application returns an area to freespace
    /// @param ap	The area returned to free space
    virtual  void	 free(Area *ap);

};

#endif	/*BestFit2_h*/
