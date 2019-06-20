#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include "usedessPatConfig.h"
#include "dbg.h"

#ifdef GOF_FOUND
#include "gof.h"
#include "mazegame.h"
#include "mazefactory.h"
#include "mazebuilder.h"
#include "textshape.h"
#endif

#ifdef GFG_FOUND
#include "gfg.h"
#endif

#ifdef LCTHW_FOUND
#include "lcthw.h"
#endif

#ifdef CS180_FOUND
#include "cs180.h"
#endif

#ifdef CONCUR_FOUND
#include "concur.h"
#endif

#ifdef MCPP_FOUND
#include "mcpp.h"
#endif

#ifdef LIN_FOUND
#include "lin.h"
#endif

#ifdef WIN_FOUND
#include "win.h"
#endif

int main (int argc, char *argv[])
{
    fprintf(stdout,"%s Version %d.%d\n",
              argv[0],
              usedessPat_VERSION_MAJOR,
              usedessPat_VERSION_MINOR);
#ifdef GOF_FOUND
    {
        auto mg = std::make_shared<gof::MazeGame>();
        mg->CreateMaze(gof::MazeFactory::Instance());

        auto sp = std::make_unique<gof::Shape>(1,2,4,5);
        gof::Point a(0,0), b(0,0);
        sp->BoundingBox(&a,&b);
        auto mp = sp->CreateManipulator();
        auto tv = std::make_unique<gof::TextView>(1,3,4,7);
        auto tsp = std::make_unique<gof::TextShape>(1,2,4,5);
    }
#endif

#ifdef CS180_FOUND
    {
        std::cout << "stable matching algo :" << std::endl;
        std::stringstream in, out;
        in << "2 m1 m2 w1 w2 m1 w2 w1 m2 w1 w2 w1 m1 m2 w2 m1 m2\0";
        cs180::StableMatching sm(in);
        std::cout << out.str();
        cs180::pq::heap<int> pq;
        pq.insert(5, 1);
        pq.insert(4, 8);
        pq.insert(2, 2);
        pq.insert(1, 4);
        pq.insert(3, 3);
        pq.insert(7, 5);
        pq.changeKey(0, 25);
        for(int i = 0;i < 6;i++)
            std::cout << pq.extractmin() << " ";
        std::cout << "\n";
    }
#endif
#ifdef GFG_FOUND
  //get number of test cases
  int t, scn;;
  int A[1010]; int B[1010]; int ress[1010];
  size_t res_arr[1010];
  printf("maximum_subarray : \n");
  scn = scanf("%d", &t);
  while (t--) {
      //get the size of array
      size_t n; scn = scanf("%zu", &n);
      //get array entries
      for (size_t i = 0; i < n; i++)
          scn = scanf("%d", &A[i]);
      int res;
      maximum_subarray(A, n, &res);
      printf("%d\n", res);
  }
  printf("find_missing_number : \n");
  scn = scanf("%d", &t);
  while (t--) {
      //get the size of array
      size_t n; scn = scanf("%zu", &n);
      //get array entries
      for (size_t i = 0; i < n; i++)
          scn = scanf("%d", &A[i]);
      int res;
      find_missing_number(A, n, &res);
      printf("%d\n", res);
  }
  printf("subarry_with_given_sum : \n");
  scn = scanf("%d", &t);
  while (t--) {
      //get the size of array
      size_t n; scn = scanf("%zu", &n);
      int s; scn = scanf("%d", &s);
      //get array entries
      for (size_t i = 0; i < n; i++)
          scn = scanf("%d", &A[i]);
      size_t res[2];
      if(!subarray_with_given_sum(A, n, s, res, 2))
        printf("%zu %zu\n", res[0], res[1]);
      else
        printf("-1\n");
  }
  printf("sort 0 1 2 : \n");
  scn = scanf("%d", &t);
  while (t--) {
      //get the size of array
      size_t n; scn = scanf("%zu", &n);
      //get array entries
      for (size_t i = 0; i < n; i++)
          scn = scanf("%d", &A[i]);
      sort_012(A, n);
      for (size_t i = 0; i < n; i++)
          printf("%d ", A[i]);
      printf("\n");
  }
  printf("equilibrium point : \n");
  scn = scanf("%d", &t);
  while (t--) {
      //get the size of array
      size_t n; scn = scanf("%zu", &n);
      //get array entries
      for (size_t i = 0; i < n; i++)
          scn = scanf("%d", &A[i]);
      size_t res;
      equilibrium_point(A, n, &res);
      printf("%zu\n", res);
  }
  printf("maximum sum increasing subsequence : \n");
  scn = scanf("%d", &t);
  while (t--) {
      //get the size of array
      size_t n; scn = scanf("%zu", &n);
      //get array entries
      for (size_t i = 0; i < n; i++)
          scn = scanf("%d", &A[i]);
      int res;
      maximum_sum_increasing_subsequence(A, n, &res);
      printf("%d\n", res);
  }
  printf("leaders in an array : \n");
  scn = scanf("%d", &t);
  while (t--) {
      //get the size of array
      size_t n; scn = scanf("%zu", &n);
      //get array entries
      for (size_t i = 0; i < n; i++)
          scn = scanf("%d", &A[i]);
      size_t res_size;
      leaders_in_an_array(A, n, B, &res_size);
      for (size_t i = 0; i < res_size; i++)
          printf("%d ", B[i]);
      printf("\n");
  }
  printf("no of platforms : \n");
  scn = scanf("%d", &t);
  while (t--) {
      //get the size of array
      size_t n; scn = scanf("%zu", &n);
      //get array entries
      for (size_t i = 0; i < n; i++)
          scn = scanf("%d", &A[i]);
      for (size_t i = 0; i < n; i++)
          scn = scanf("%d", &B[i]);
      int res;
      minimum_platforms(A, B, n, &res);
      printf("%d\n", res);
  }
  printf("maximums_of_subarray_size_k : \n");
  scn = scanf("%d", &t);
  while (t--) {
      //get the size of array
      size_t n; scn = scanf("%zu", &n);
      size_t k; scn = scanf("%zu", &k);
      //get array entries
      for (size_t i = 0; i < n; i++)
          scn = scanf("%d", &A[i]);
      size_t res_size;
      maximums_of_subarray_size_k(A, n, k, B, &res_size);
      for (size_t i = 0; i < res_size; i++)
          printf("%d ", B[i]);
      printf("\n");
  }
  printf("reverse_array_in_groups : \n");
  scn = scanf("%d", &t);
  while (t--) {
      //get the size of array
      size_t n; scn = scanf("%zu", &n);
      size_t k; scn = scanf("%zu", &k);
      //get array entries
      for (size_t i = 0; i < n; i++)
          scn = scanf("%d", &A[i]);
      reverse_array_in_groups(A, n, k);
      for (size_t i = 0; i < n; i++)
          printf("%d ", A[i]);
      printf("\n");
  }
  printf("kth_smallest_element : \n");
  scn = scanf("%d", &t);
  while (t--) {
      //get the size of array
      size_t n; scn = scanf("%zu", &n);
      //get array entries
      for (size_t i = 0; i < n; i++)
          scn = scanf("%d", &A[i]);
      size_t k; scn = scanf("%zu", &k);
      int res;
      kth_smallest_element(A, n, k, &res);
      printf("%d\n", res);
  }
  printf("trapping_rainwater : \n");
  scn = scanf("%d", &t);
  while (t--) {
      //get the size of array
      size_t n; scn = scanf("%zu", &n);
      //get array entries
      for (size_t i = 0; i < n; i++)
          scn = scanf("%d", &A[i]);
      long long res;
      trapping_rainwater(A, n, &res);
      printf("%lld\n", res);
  }
  printf("pythagorean_triplet : \n");
  scn = scanf("%d", &t);
  while (t--) {
      //get the size of array
      size_t n; scn = scanf("%zu", &n);
      //get array entries
      for (size_t i = 0; i < n; i++)
          scn = scanf("%d", &A[i]);
      pythagorean_triplet(A, n);
      for (size_t i = 0; i < n; i++)
          printf("%d ", A[i]);
      printf("\n");
  }
  printf("chocolate_distribution : \n");
  scn = scanf("%d", &t);
  while (t--) {
      //get the size of array
      size_t n; scn = scanf("%zu", &n);
      //get array entries
      for (size_t i = 0; i < n; i++)
          scn = scanf("%d", &A[i]);
      size_t m; scn = scanf("%zu", &m);
      int res;
      chocolate_distribution(A, n, m, &res);
      printf("%d\n", res);
  }
  printf("stock_buy_and_sell : \n");
  scn = scanf("%d", &t);
  while (t--) {
      //get the size of array
      size_t n; scn = scanf("%zu", &n);
      //get array entries
      for (size_t i = 0; i < n; i++)
          scn = scanf("%d", &A[i]);
      size_t res_size;
      stock_buy_and_sell(A, n, res_arr, &res_size);
      for (size_t i = 0; i < res_size; i++)
          printf("%zu", res_arr[i]);
      printf("\n");

  }
  printf("elements_with_left_side_smaller_and_right_side_greater : \n");
  scn = scanf("%d", &t);
  while (t--) {
      //get the size of array
      size_t n; scn = scanf("%zu", &n);
      //get array entries
      for (size_t i = 0; i < n; i++)
          scn = scanf("%d", &A[i]);
      int res;
      elements_with_left_side_smaller_and_right_side_greater(A, n, &res);
      printf("%d\n", res);
  }
  printf("convert_array_into_zigzag_fashion : \n");
  scn = scanf("%d", &t);
  while (t--) {
      //get the size of array
      size_t n; scn = scanf("%zu", &n);
      //get array entries
      for (size_t i = 0; i < n; i++)
          scn = scanf("%d", &A[i]);
      convert_array_into_zigzag_fashion(A, n);
      for (size_t i = 0; i < n; i++)
          printf("%d ", A[i]);
      printf("\n");
  }
  printf("find_the_element_that_appears_once_in_sorted_array : \n");
  scn = scanf("%d", &t);
  while (t--) {
      //get the size of array
      size_t n; scn = scanf("%zu", &n);
      //get array entries
      for (size_t i = 0; i < n; i++)
          scn = scanf("%d", &A[i]);
      int res;
      find_the_element_that_appears_once_in_sorted_array(A, n, &res);
      printf("%d\n", res);
  }
  printf("kth_largest_element_in_a_stream : \n");
  scn = scanf("%d", &t);
  while (t--) {
      //get the size of array
      size_t k; scn = scanf("%zu", &k);
      size_t n; scn = scanf("%zu", &n);
      //get array entries
      for (size_t i = 0; i < n; i++)
          scn = scanf("%d", &A[i]);
      size_t res_size;
      kth_largest_element_in_a_stream(A, n, k, B, &res_size);
      for (size_t i = 0; i < res_size; i++)
          printf("%d ", B[i]);
      printf("\n");
  }
  printf("relative_sorting : \n");
  scn = scanf("%d", &t);
  while (t--) {
      //get the size of array
      size_t n; scn = scanf("%zu", &n);
      size_t m; scn = scanf("%zu", &m);
      //get array entries
      for (size_t i = 0; i < n; i++)
          scn = scanf("%d", &A[i]);
      for (size_t i = 0; i < m; i++)
          scn = scanf("%d", &B[i]);
      size_t res_size;
      relative_sorting(A, n, B, m, ress, &res_size);
      for (size_t i = 0; i < res_size; i++)
          printf("%d ", ress[i]);
      printf("\n");
  }
  printf("spirally_traversing_a_matrix : \n");
  scn = scanf("%d", &t);
  while (t--) {
      //get the size of array
      size_t m; scn = scanf("%zu", &m);
      size_t n; scn = scanf("%zu", &n);
      //get array entries
      for (size_t i = 0; i < m; i++)
          for(size_t j = 0; j < n; j++)
          scn = scanf("%d", &A[n*i + j]);
      size_t res_size;
      spirally_traversing_a_matrix(A, m, n, B, &res_size);
      for (size_t i = 0; i < res_size; i++)
          printf("%d ", B[i]);
      printf("\n");
  }
  printf("sorting_array_elements_by_frequency : \n");
  scn = scanf("%d", &t);
  while (t--) {
      //get the size of array
      size_t n; scn = scanf("%zu", &n);
      //get array entries
      for (size_t i = 0; i < n; i++)
              scn = scanf("%d", &A[i]);
      size_t res_size;
      sorting_array_elements_by_frequency(A, n, B, &res_size);
      for (size_t i = 0; i < res_size; i++)
          printf("%d ", B[i]);
      printf("\n");
  }
  struct arr As[105];
  printf("largest_number_formed_by_array : \n");
  scn = scanf("%d", &t);
  while (t--) {
      //get the size of array
      size_t n; scn = scanf("%zu", &n);
      //get array entries
      for (size_t i = 0; i < n; i++)
          scn = scanf("%s", As[i].a);
      char str[50];
      size_t res_size;
      largest_number_formed_by_array(As, n, str, &res_size);
      printf("%s\n", str);
  }
#endif // GFG

#ifdef LCTHW_FOUND
  printf("Exercise 1:\n");
  ex1(stdout);
  printf("Exercise 3:\n");
  ex3(stdout);
  printf("Exercise 7:\n");
  ex7(stdout);
  printf("Exercise 8:\n");
  ex8(argc, argv, stdout);
  printf("Exercise 9:\n");
  ex9(stdout);
  printf("Exercise 10:\n");
  ex10(argc, argv, stdout);
  printf("Exercise 11:\n");
  ex11(stdout);
  printf("Exercise 12:\n");
  ex12(stdout);
  printf("Exercise 13:\n");
  ex13(argc, argv, stdout);
  printf("Exercise 14:\n");
  ex14(argc, argv, stdout);
  printf("Exercise 15:\n");
  ex15(stdout);
  //printf("Exercise 16:\n");
  //ex16(argc, argv);
  printf("Exercise 17:\n");
  //ex17(argc, argv);
  printf("Exercise 18:\n");
  ex18(argc, argv);
  printf("Exercise 19:\n");
  ex19(argc, argv);
  printf("Exercise 22:\n");
  ex22(argc, argv);
  printf("Exercise 23:\n");
  ex23(argc, argv);
  printf("Exercise 24:\n");
  ex24(argc, argv);
  printf("Exercise 25:\n");
  ex25(argc, argv);
#endif

#ifdef CONCUR_FOUND
    exec(std::cout);
#endif

#ifdef MCPP_FOUND
    mcpp_test tt;
    tt();
#endif

#ifdef LIN_FOUND
    lin ln;
    ln();
#endif

#ifdef WIN_FOUND
    win wn;
    wn();
#endif
  return 0;
}
