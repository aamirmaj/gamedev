#include <math.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

// vector class
// can represent geometry or a color 
// 3 dimensions + coordinate
//            or
//        RGB + alpha

class vector {
	public:
		vector(){}
		vector(float e0, float e1, float e2){
			e[0] = e0;
			e[1] = e1;
			e[2] = e2;
		}
		// inline to reduce overhead
		inline float x() const {
			return e[0];
		}
		inline float y() const {
			return e[1];
		}
		inline float z() const {
			return e[2];
		}
		inline float r() const {
			return e[0];
		}
		inline float g() const {
			return e[1];
		}
		inline float b() const {
			return e[2];
		}
		
		// operators
		inline const vector& operator+() const {
			return *this;
		}
		inline const vector& operator-() const {
			return vector(-e[0], -e[1], -e[2]);
		}
		inline float operator[](int i) const {
			return e[i];
		}
		inline float& operator[](int i) {
			return e[i];
		};

		inline vector& operator+=(const vector &v2);
		inline vector& operator-=(const vector &v2);
		inline vector& operator*=(const vector &v2);
		inline vector& operator/=(const vector &v2);
		inline vector& operator*=(const float t);
		inline vector& operator/=(const float t);

		// geometry functions
		inline float length() const {
			return sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
		}
		inline float squared_length() const {
			return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
		}
		inline void make_unit_vector();


		float e[3];
};

// vector functions

inline istream& operator>>(istream &is, vector &t){
	is >> t.e[0] >> t.e[1] >> t.e[2];
	return is;
}

inline ostream& operator<<(ostream &os, vector &t){
	os << t.e[0] << " " << t.e[1] << " " << t.e[2];
	return os;
}

// scale of 1
inline void vector::make_unit_vector(){
	float k = 1.0 / sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
	e[0] *= k;
	e[1] *= k;
	e[2] *= k;
}

inline vector operator+(const vector &v1, const vector &v2){
	return vector(v1.e[0] + v2.e[0], v1.e[1] + v2.e[2],v1.e[2] + v2.e[2]);
}

inline vector operator-(const vector &v1, const vector &v2){
	return vector(v1.e[0] - v2.e[0], v1.e[1] - v2.e[2],v1.e[2] - v2.e[2]);
}


inline vector operator*(const vector &v1, const vector &v2){
	return vector(v1.e[0] * v2.e[0], v1.e[1] * v2.e[2],v1.e[2] * v2.e[2]);
}

inline vector operator/(const vector &v1, const vector &v2){
	return vector(v1.e[0] / v2.e[0], v1.e[1] / v2.e[2],v1.e[2] / v2.e[2]);
}

inline vector operator*(float t, const vector &v){
	return vector(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline vector operator/(float t, const vector &v){
	return vector(t / v.e[0], t / v.e[1], t / v.e[2]);
}

inline vector operator*(const vector &v, float t){
	return vector(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline vector operator/(const vector &v, float t){
	return vector(v.e[0] / t, v.e[1] / t, v.e[2] / t);
}

// dot product
inline float dot(const vector &v1, const vector &v2){
	return v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1] + v1.e[2] * v2.e[2];
}

// cross product
inline vector cross(const vector &v1, const vector &v2){
	return vector(v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1],
				  v1.e[2] * v2.e[0] - v1.e[0] * v2.e[2],
				  v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0]);
}

inline vector& vector::operator+=(const vector &v){
	e[0] += v.e[0];
	e[1] += v.e[1];
	e[2] += v.e[2];
	return *this;
}

inline vector& vector::operator*=(const vector &v){
	e[0] *= v.e[0];
	e[1] *= v.e[1];
	e[2] *= v.e[2];
	return *this;
}

inline vector& vector::operator/=(const vector &v){
	e[0] /= v.e[0];
	e[1] /= v.e[1];
	e[2] /= v.e[2];
	return *this;
}

inline vector& vector::operator*=(const float t){
	e[0] *= t;
	e[1] *= t;
	e[2] *= t;
	return *this;
}

inline vector& vector::operator/=(const float t){
	float k = 1.0/t;
	e[0] *= t;
	e[1] *= t;
	e[2] *= t;
	return *this;
}

inline vector unit_vector(vector v){
	return v / v.length();
}
