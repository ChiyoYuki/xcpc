// import MIL.Common
// import Mathlib.Data.Real.Basic
// -- An example.
// example (a b c : ℝ) : a * b * c = b * (a * c) := by
//   rw [mul_comm a b]
//   rw [mul_assoc b a c]

// -- Try these.
// example (a b c : ℝ) : c * b * a = b * (a * c) := by
//   rw [mul_comm c b]
//   rw [mul_assoc b c a]
//   rw [mul_comm c a]

// example (a b c : ℝ) : a * (b * c) = b * (a * c) := by
//   rw [mul_comm a (b * c)]
//   rw [mul_assoc b c a]
//   rw [mul_comm c a]

// -- An example.
// example (a b c : ℝ) : a * b * c = b * c * a := by
//   rw [mul_assoc]
//   rw [mul_comm]
#include<bits/stdc++.h>
// /- Try doing the first of these without providing any arguments at all,
//    and the second with only one argument. -/
// example (a b c : ℝ) : a * (b * c) = b * (c * a) := by
//   rw [mul_comm]
//   rw [mul_assoc]

// example (a b c : ℝ) : a * (b * c) = b * (a * c) := by
//   rw [mul_comm]     -- rw [← mul_assoc]
//   rw [mul_assoc]    -- rw [mul_comm a]
//   rw [mul_comm c] -- rw [mul_assoc]
using namespace std;
// -- Using facts from the local context.
// example (a b c d e f : ℝ) (h : a * b = c * d) (h' : e = f) : a * (b * e) = c * (d * f) := by
//   rw [h']
//   rw [← mul_assoc]
//   rw [h]
//   rw [mul_assoc]

// example (a b c d e f : ℝ) (h : b * c = e * f) : a * b * c * d = a * e * f * d := by
//   rw [mul_assoc a b c]
//   rw [h]
//   rw [← mul_assoc]
int
// example (a b c d : ℝ) (hyp : c = b * a - d) (hyp' : d = a * b) : c = 0 := by
//   rw [hyp]
//   rw [mul_comm]
//   rw [hyp']
//   rw [sub_self]

// example (a b c d e f : ℝ) (h : a * b = c * d) (h' : e = f) : a * (b * e) = c * (d * f) := by
//   rw [h', ← mul_assoc, h, mul_assoc]
main()
// section

// variable (a b c d e f : ℝ)

// example (h : a * b = c * d) (h' : e = f) : a * (b * e) = c * (d * f) := by
//   rw [h', ← mul_assoc, h, mul_assoc]
{
// end

// section
// variable (a b c : ℝ)

// #check a
// #check a + b
// #check (a : ℝ)
// #check mul_comm a b
// #check (mul_comm a b : a * b = b * a)
// #check mul_assoc c a b
// #check mul_comm a
// #check mul_comm
cout<<
// end

// section
// variable (a b : ℝ)

// example : (a + b) * (a + b) = a * a + 2 * (a * b) + b * b := by
//   rw [mul_add, add_mul, add_mul]
//   rw [← add_assoc, add_assoc (a * a)]
//   rw [mul_comm b a, ← two_mul]
"Ciallo!"
// example : (a + b) * (a + b) = a * a + 2 * (a * b) + b * b :=
//   calc
//     (a + b) * (a + b) = a * a + b * a + (a * b + b * b) := by
//       rw [mul_add, add_mul, add_mul]
//     _ = a * a + (b * a + a * b) + b * b := by
//       rw [← add_assoc, add_assoc (a * a)]
//     _ = a * a + 2 * (a * b) + b * b := by
//       rw [mul_comm b a, ← two_mul]

// example : (a + b) * (a + b) = a * a + 2 * (a * b) + b * b :=
//   calc
//     (a + b) * (a + b) = a * a + b * a + (a * b + b * b) := by
//       rw [mul_add, add_mul, add_mul]
//     _ = a * a + (b * a + a * b) + b * b := by
//       rw [← add_assoc, add_assoc (a * a)]
//     _ = a * a + 2 * (a * b) + b * b := by
//       rw [mul_comm b a, ← two_mul]
<<
// end

// -- Try these. For the second, use the theorems listed underneath.
// section
// variable (a b c d : ℝ)

// example : (a + b) * (c + d) = a * c + a * d + b * c + b * d := by
//   rw [add_mul, mul_add, mul_add, ← add_assoc, add_assoc (a * c), add_comm (a * d), ← add_assoc]
endl
// example (a b : ℝ) : (a + b) * (a - b) = a ^ 2 - b ^ 2 := by
//   rw [add_mul, mul_sub, mul_sub, add_sub, mul_comm a b, sub_eq_add_neg (a * a), add_assoc, neg_add_cancel, add_zero, pow_two, pow_two]

// #check pow_two a
// #check mul_sub a b c
// #check add_mul a b c
// #check add_sub a b c
// #check sub_sub a b c
// #check add_zero a
;
// end

// -- Examples.

// section
// variable (a b c d : ℝ)

// example (a b c d : ℝ) (hyp : c = d * a + b) (hyp' : b = a * d) : c = 2 * a * d := by
//   rw [hyp'] at hyp
//   rw [mul_comm d a] at hyp
//   rw [← two_mul (a * d)] at hyp
//   rw [← mul_assoc 2 a d] at hyp
//   exact hyp
return
// example : c * b * a = b * (a * c) := by
//   ring

// example : (a + b) * (a + b) = a * a + 2 * (a * b) + b * b := by
//   ring

// example : (a + b) * (a - b) = a ^ 2 - b ^ 2 := by
//   ring
0
// example (hyp : c = d * a + b) (hyp' : b = a * d) : c = 2 * a * d := by
//   rw [hyp, hyp']
//   ring

// end
;}
// example (a b c : ℕ) (h : a + b = c) : (a + b) * (a + b) = a * c + b * c := by
//   nth_rw 2 [h]
//   rw [add_mul]
