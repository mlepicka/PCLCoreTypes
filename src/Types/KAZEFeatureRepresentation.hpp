#ifndef KAZEFeatureRepresentation_HPP_
#define KAZEFeatureRepresentation_HPP_

#define PCL_NO_PRECOMPILE
#include <pcl/point_types.h>
#include <pcl/point_representation.h>

#include <Types/PointXYZKAZE.hpp>


/*
 * \brief Class used for transformation from KAZE descriptor to array of floats.
 */
class KAZEFeatureRepresentation: public pcl::DefaultFeatureRepresentation <PointXYZKAZE> 
{
	/// Templatiated number of KAZE descriptor dimensions.
	using pcl::PointRepresentation<PointXYZKAZE>::nr_dimensions_;
	bool extended;
	
	public:
	KAZEFeatureRepresentation (bool extended=true)
	{
		// Define the number of dimensions.
		if(extended){
			nr_dimensions_ = 64 ;
		}
		else{
			nr_dimensions_ = 128 ;
		}
		trivial_ = false ;
	}

	/// Overrides the copyToFloatArray method to define our feature vector
	virtual void copyToFloatArray (const PointXYZKAZE &p, float * out) const
	{
		//This representation is only for determining correspondences (not for use in Kd-tree for example - so use only the KAZE part of the point.
		for (register int i = 0; i < nr_dimensions_ ; i++)
			out[i] = p.descriptor[i];//p.descriptor.at<float>(0, i) ;
	}
};


#endif /* KAZEFeatureRepresentation_HPP_ */
