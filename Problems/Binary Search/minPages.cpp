#include "../../Utils/utils.h"
#include <numeric>
#include <climits>


/*

Given number of pages in n different books and m students, The books are arranged in any order (not necessarily ascending) of number of pages.
Every student is assigned to read some consecutive segment of books.
The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum.
Find the maximum number of pages that a student will have to read.

*/
bool canDivideBooks(const vector<int>& books,int m,int maxPages){
    int currentPages = 0;// Current sum of pages in the current segment
    int segments = 0;// Number of segments formed so far
    for(int book : books){
        if(book > maxPages){// If the current book has more pages than the maximum allowed pages
            return false;
        }
        if(currentPages + book > maxPages){// If adding the current book exceeds the maximum allowed pages
            segments++;
            currentPages = book;
            if(segments > m){// If the number of segments exceeds the number of students
            return false;
        }
        }
        else{// If adding the current book does not exceed the maximum allowed pages
            currentPages += book;
        }
    }
    return segments < m;// Return true if the number of segments is less than the number of students
}


int minPages(vector<int> books, int m){
    int start = *min_element(books.begin(), books.end());// Minimum possible value for a segment
    int end = accumulate(books.begin(), books.end(), 0);// Maximum possible value for a segment
    int result = end;// Initialize result with the maximum possible value
    while(start <= end){// Binary search
        int mid = start + (end - start)/2;// Midpoint of the search range
        bool canDivide = canDivideBooks(books, m, mid);// Check if it's possible to divide the books into m segments with a maximum segment sum of mid
        if(canDivide){// If it's possible to divide the books into m segments with a maximum segment sum of mid
            result = mid;// Update the result to the current mid
            end = mid - 1;// Try to find a smaller maximum segment sum (go left)
        }
        else{
            start = mid + 1;// Try to find a larger maximum segment sum (go right)
        }
    }
    return result;// Return the minimum maximum segment sum
}




int main(){

/*
Example:
Input:
books = [10, 20,30,15]
students = 2
Output:
45
*/

    vector<int> books = {10, 20,30,15};
    int students = 2;
    cout << minPages(books, students) << endl;//
    return 0;
}