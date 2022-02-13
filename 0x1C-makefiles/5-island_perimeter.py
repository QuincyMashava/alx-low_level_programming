#!/usr/bin/python3
"""
Module Island Perimeter
"""

def island_perimeter(grid):
    """Calculating the perimeter of the grid where """
    perimeter = 0
    for row in range(len(grid)):
        for col in range(len(grid[0])):
            if grid[row][col] == 1:
                if row == 0 or grid[row -1][col] == 0:
                    perimeter += 1 #this represents the topside
                if row == (len(grid) - 1) or grid[row + 1][col] == 0:
                    perimeter += 1 #this represents the bottom side
                if col == 0 or grid[row][col - 1] == 0:
                    perimeter += 1 #this represents the left side
                if col == (len(grid[0]) - 1) or grid[row][col + 1] == 0:
                    perimeter += 1 #this represents the right side

    return perimeter
                           
            
