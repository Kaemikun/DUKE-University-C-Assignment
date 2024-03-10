/*#include <stdio.h>
#include <stdlib.h>
//I've provided "min" and "max" functions in
//case they are useful to you
int min (int a, int b) {
  if (a < b) {

      	  return a;
  }
  return b;
}
int max (int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

//Declare your rectangle structure here!
typedef struct rectangle_t {
    int x;
    int y;
    int width;
    int height;
} rectangle;


rectangle canonicalize(rectangle r) {

//	rectangle canonicalize(rectangle r) {
    // Ensure width and height are non-negative
    if (r.width < 0) {
        r.x += r.width; // Adjust x coordinate
        r.width = -r.width; // Make width positive
    }
    if (r.height < 0) {
        r.y += r.height; // Adjust y coordinate
        r.height = -r.height; // Make height positive
    }
    return r;
//}

      	//WRITE THIS FUNCTION
//  return r;
}rectangle intersection(rectangle r1, rectangle r2) {
  //WRITE THIS FUNCTION
  r1 = canonicalize(r1);
    r2 = canonicalize(r2);
    
    // Calculate intersection coordinates
    int x1 = max(r1.x, r2.x);
    int y1 = max(r1.y, r2.y);
    int x2 = min(r1.x + r1.width, r2.x + r2.width);
    int y2 = min(r1.y + r1.height, r2.y + r2.height);


    // Check if there's no intersection
    if (x1 >= x2 || y1 >= y2) {
        // Return an empty rectangle
        rectangle empty = {0, 0, 0, 0};
        return empty;
    }
    
    // Calculate intersection rectangle
    rectangle intersect = {x1, y1, x2 - x1, y2 - y1};
    return intersect;
//	return r1;
}*/
/**rectangle intersection(rectangle r1, rectangle r2) {
    // Canonicalize rectangles
    r1 = canonicalize(r1);
    r2 = canonicalize(r2);

    // Calculate intersection coordinates
    int x1 = max(r1.x, r2.x);
    int y1 = max(r1.y, r2.y);
    int x2 = min(r1.x + r1.width, r2.x + r2.width);
    int y2 = min(r1.y + r1.height, r2.y + r2.height);

    // Check if there's no intersection
    if (x1 >= x2 || y1 >= y2) {
        // Return an empty rectangle with a flag indicating no intersection
        rectangle empty = {0, 0, 0, 0}; // 1 indicates no intersection
        return empty;
    }

    // Calculate intersection rectangle
    rectangle intersect = {x1, y1, x2 - x1, y2 - y1}; // 0 indicates intersection
    return intersect;
}


//You should not need to modify any code below this line
void printRectangle(rectangle r) {
  r = canonicalize(r);
  if (r.width == 0 && r.height == 0) {
    printf("<empty>\n");

  }
  else {
    printf("(%d,%d) to (%d,%d)\n", r.x, r.y, 
	                           r.x + r.width, r.y + r.height);
  }
}

int main (void) {
  rectangle r1;
  rectangle r2;
  rectangle r3;
  rectangle r4;

  r1.x = 2;
  r1.y = 3;
  r1.width = 5;
  r1.height = 6;
  printf("r1 is ");
  printRectangle(r1);

  r2.x = 4;
  r2.y = 5;
  r2.width = -5;
  r2.height = -7;
  printf("r2 is ");
  printRectangle(r2);
  
  r3.x = -2;
  r3.y = 7;
  r3.width = 7;
  r3.height = -10;
  printf("r3 is ");
  printRectangle(r3);

  r4.x = 0;
  r4.y = 7;
  r4.width = -4;
  r4.height = 2;
  printf("r4 is ");
  printRectangle(r4);

  //test everything with r1
  rectangle i = intersection(r1,r1);
  printf("intersection(r1,r1): ");
  printRectangle(i);

  i = intersection(r1,r2);
  printf("intersection(r1,r2): ");
  printRectangle(i);
  
  i = intersection(r1,r3);
  printf("intersection(r1,r3): ");
  printRectangle(i);

  i = intersection(r1,r4);
  printf("intersection(r1,r4): ");
  printRectangle(i);

  //test everything with r2
  i = intersection(r2,r1);
  printf("intersection(r2,r1): ");
  printRectangle(i);

  i = intersection(r2,r2);
  printf("intersection(r2,r2): ");
  printRectangle(i);
  
  i = intersection(r2,r3);
  printf("intersection(r2,r3): ");
  printRectangle(i);

  i = intersection(r2,r4);
  printf("intersection(r2,r4): ");
  printRectangle(i);

  //test everything with r3
  i = intersection(r3,r1);
  printf("intersection(r3,r1): ");
  printRectangle(i);

  i = intersection(r3,r2);
  printf("intersection(r3,r2): ");
  printRectangle(i);
  
  i = intersection(r3,r3);
  printf("intersection(r3,r3): ");
  printRectangle(i);

  i = intersection(r3,r4);
  printf("intersection(r3,r4): ");
  printRectangle(i);

  //test everything with r4
  i = intersection(r4,r1);
  printf("intersection(r4,r1): ");
  printRectangle(i);

  i = intersection(r4,r2);
  printf("intersection(r4,r2): ");
  printRectangle(i);
  
  i = intersection(r4,r3);
  printf("intersection(r4,r3): ");
  printRectangle(i);

  i = intersection(r4,r4);
  printf("intersection(r4,r4): ");
  printRectangle(i);


  return EXIT_SUCCESS;


}*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
    int width;
    int height;
} rectangle;

// Function prototypes
int min(int a, int b);
int max(int a, int b);
rectangle canonicalize(rectangle r);
rectangle intersection(rectangle r1, rectangle r2);
void printRectangle(rectangle r);

int min(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

rectangle canonicalize(rectangle r) {
    if (r.width < 0) {
        r.x += r.width;
        r.width = -r.width;
    }
    if (r.height < 0) {
        r.y += r.height;
        r.height = -r.height;
    }
    return r;
}

rectangle intersection(rectangle r1, rectangle r2) {
    r1 = canonicalize(r1);
    r2 = canonicalize(r2);

    int x1 = max(r1.x, r2.x);
    int y1 = max(r1.y, r2.y);
    int x2 = min(r1.x + r1.width, r2.x + r2.width);
    int y2 = min(r1.y + r1.height, r2.y + r2.height);

    // Check if there is no intersection
    if (x2 < x1 || y2 < y1) {
        rectangle no_intersection = {0, 0, 0, 0};
        return no_intersection;
    }

    rectangle result;
    result.x = x1;
    result.y = y1;
    result.width = x2 - x1;
    result.height = y2 - y1;

    return result;
}

void printRectangle(rectangle r) {
    r = canonicalize(r);
    if (r.width == 0 && r.height == 0) {
        printf("<empty>\n");
    }
    else {
        printf("(%d,%d) to (%d,%d)\n", r.x, r.y,
                                        r.x + r.width, r.y + r.height);
    }
}

int main(void) {
    rectangle r1 = {2, 3, 5, 6};
    rectangle r2 = {4, 5, -5, -7};
    rectangle r3 = {-2, 7, 7, -10};
    rectangle r4 = {0, 7, -4, 2};

    printf("r1 is ");
    printRectangle(r1);
    printf("r2 is ");
    printRectangle(r2);
    printf("r3 is ");
    printRectangle(r3);
    printf("r4 is ");
    printRectangle(r4);

    // Test everything with r1
    rectangle i = intersection(r1, r1);
    printf("intersection(r1, r1): ");
    printRectangle(i);

    i = intersection(r1, r2);
    printf("intersection(r1, r2): ");
    printRectangle(i);

    i = intersection(r1, r3);
    printf("intersection(r1, r3): ");
    printRectangle(i);

    i = intersection(r1, r4);
    printf("intersection(r1, r4): ");
    printRectangle(i);

    // Test everything with r2
    i = intersection(r2, r1);
    printf("intersection(r2, r1): ");
    printRectangle(i);

    i = intersection(r2, r2);
    printf("intersection(r2, r2): ");
    printRectangle(i);

    i = intersection(r2, r3);
    printf("intersection(r2, r3): ");
    printRectangle(i);

    i = intersection(r2, r4);
    printf("intersection(r2, r4): ");
    printRectangle(i);

    // Test everything with r3
    i = intersection(r3, r1);
    printf("intersection(r3, r1): ");
    printRectangle(i);

    i = intersection(r3, r2);
    printf("intersection(r3, r2): ");
    printRectangle(i);

    i = intersection(r3, r3);
    printf("intersection(r3, r3): ");
    printRectangle(i);

    i = intersection(r3, r4);
    printf("intersection(r3, r4): ");
    printRectangle(i);

    // Test everything with r4
    i = intersection(r4, r1);
    printf("intersection(r4, r1): ");
    printRectangle(i);

    i = intersection(r4, r2);
    printf("intersection(r4, r2): ");
    printRectangle(i);

    i = intersection(r4, r3);
    printf("intersection(r4, r3): ");
    printRectangle(i);

    i = intersection(r4, r4);
    printf("intersection(r4, r4): ");
    printRectangle(i);

    return EXIT_SUCCESS;
}

