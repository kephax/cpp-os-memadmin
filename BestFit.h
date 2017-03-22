#pragma once
#ifndef	__BestFit_h__
#define	__BestFit_h__ 2.2
//#ident	"@(#)BestFit.h	2.2	AKK	20140130"

/** @file BestFit.h
 *  @brief The class that implements the lazy version of the BestFit algorithm.
 *  @author BUA MIRZA
 *  @version 1.0		20150525
 */




#include "Fitter.h"


/// @class BestFit
/// Het BestFit algorithme gebruikt het eerste
/// gevonden bruikbare gebied in de resource map.
/// This is the lazy version.
class	BestFit : public Fitter
{
public:

	explicit	// see: http://en.cppreference.com/w/cpp/language/explicit
	/// @param cflag	initial status of check-mode
	/// @param type		name of this algorithm (default=BestFit)
	BestFit(bool cflag=false, const char *type = "BestFit (lazy)") : Fitter(cflag, type) {}

	/// Cleanup free areas
	~BestFit();

	void	 setSize(int new_size);	///< initialize memory size

	/// Ask for an area of at least 'wanted' units.
	/// @returns	An area or 0 if not enough freespace available
	virtual  Area	*alloc(int wanted);	// application asks for space

	/// The application returns an area to freespace.
	/// @param ap	The area returned to free space
	virtual  void	free(Area *ap);

protected:

	/// List of all the available free areas
	std::list<Area*>  areas;

	/// For debugging this function shows the free area list
	virtual	 void	dump();

	/// This is the actual function that searches for space.
	/// @returns	An area or 0 if not enough freespace available
	Area 	*searcher(int);

	/// This function is called when the searcher can not find space.
	/// It tries to reclaim fragmented space by merging adjacent free areas.
	/// @returns true if free areas could be merged, false if no adjacent areas exist
	virtual	 bool	  reclaim();

	virtual  void	updateStats();	///< update resource map statistics
};

#endif	/*BestFit_h*/

