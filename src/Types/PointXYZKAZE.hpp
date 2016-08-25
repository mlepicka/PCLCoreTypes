#ifndef POINTXYZKAZE_HPP_
#define POINTXYZKAZE_HPP_

#define PCL_NO_PRECOMPILE
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/io/pcd_io.h>

#include <pcl/point_representation.h>

#include <pcl/filters/passthrough.h>
#include <pcl/filters/impl/passthrough.hpp>

#include "pcl/impl/instantiate.hpp"

#include <boost/preprocessor.hpp>

struct PointXYZKAZE
{
  PCL_ADD_POINT4D;                  // preferred way of adding a XYZ+padding
  float descriptor[128];
  int multiplicity; 
  int pointId;
  bool extended;
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW
} EIGEN_ALIGN16;
 
POINT_CLOUD_REGISTER_POINT_STRUCT (PointXYZKAZE           // here we assume a XYZ + "test" (as fields)
                                   ,(float, x, x)
                                   (float, y, y)
                                   (float, z, z)
                                   (float[128], descriptor, descriptor)
                                   (int, multiplicity, multiplicity)
                                   (int, pointId, pointId)
)


namespace pcl{
template<> 
class DefaultPointRepresentation<PointXYZKAZE> : public PointRepresentation<PointXYZKAZE>
  {
    public:
      DefaultPointRepresentation ()
      {
        nr_dimensions_ = 3;
        trivial_ = true;
      }

      virtual void
      copyToFloatArray (const PointXYZKAZE &p, float * out) const
      {
        out[0] = p.x;
        out[1] = p.y;
        out[2] = p.z;
      }
  };	
}



#endif /* POINTXYZKAZE_HPP_ */
