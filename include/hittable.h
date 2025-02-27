#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

class hit_record {
public: 
	point3 p;
	vec3 normal;
	double t;
};

class hittable {
public:
	virtual ~hittable() = default;
	virtual bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const = 0;
	vec3 oc = center - r.origin();
	auto a = r.direction().length_squared();
	auto h = dot(r.direction(), oc);
	auto c = oc.length_squared() - radius * radius;
	auto discriminant = h * h - a * c;
	if (discriminant < 0) {
		return -1;
	}
	else {
		return (h - std::sqrt(discriminant)) / (a);
	}
};
#endif // !HITTABLE_H
