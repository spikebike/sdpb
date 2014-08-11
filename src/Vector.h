#ifndef SDP_BOOTSTRAP_VECTOR_H_
#define SDP_BOOTSTRAP_VECTOR_H_

#include <algorithm>
#include <vector>
#include <assert.h>
#include "types.h"
#include "util.h"

using std::vector;

typedef vector<Real> Vector;

inline Real maxAbsVector(const Vector &v) {
  return abs(*std::max_element(v.begin(), v.end(), compareAbs));
}  

inline void fillVector(Vector &v, const Real &a) {
  std::fill(v.begin(), v.end(), a);
}

inline void scaleVector(Vector &v, const Real &a) {
  for (unsigned int i = 0; i < v.size(); i++)
    v[i] *= a;
}

inline void addVector(Vector &v, const Vector &u) {
  assert(v.size() == u.size());

  for (unsigned int i = 0; i < v.size(); i++)
    v[i] += u[i];
}

inline Real dotProduct(const Vector &u, const Vector v) {
  Real result = 0;
  for (unsigned int i = 0; i < u.size(); i++)
    result += u[i]*v[i];
  return result;
}

#endif  // SDP_BOOTSTRAP_VECTOR_H_
