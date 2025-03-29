#ifndef AABB_H
#define AABB_H

class aabb {
public:
	interval x, y, z;

	aabb() {}

	aabb(const interval& x, const interval& y, const interval& z)
		: x(x), y(y), z(z) {}

	aabb(const point3& a, const point3& b) {

		x = (a[0] <= b[0]) ? interval(a[0], b[0]) : interval(b[0], a[0]);
		x = (a[1] <= b[1]) ? interval(a[1], b[1]) : interval(b[1], a[1]);
		x = (a[2] <= b[2]) ? interval(a[2], b[2]) : interval(b[2], a[2]);
	}

	const interval& axis_interval(int n) const {
		if (n == 1) return y;
		if (n == 2) return z;
		return x;
	}

	bool hit(const ray& r, interval ray_t) const {
		const point3& ray_orig = r.origin();
		const double adinv = 1.0 / ray_dir[axis];

		auto t0 = (ax.min - ray_orig[axis]) * adinv;
		auto t1 = (ax.min - ray_orig[axis]) * adinv;
	}
};
#endif // !AABB_H
