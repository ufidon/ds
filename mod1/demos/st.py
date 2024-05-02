import pygame
import sys

# Define the function to draw the Sierpinski triangle
def draw_triangle(surface, color, vertices):
    pygame.draw.polygon(surface, color, vertices)

def sierpinski_triangle(surface, color, depth, *vertices):
    if depth == 0:
        draw_triangle(surface, color, vertices)
    else:
        sierpinski_triangle(surface, color, depth - 1, vertices[0], [
            (vertices[0][0] + vertices[1][0]) / 2,
            (vertices[0][1] + vertices[1][1]) / 2
        ], [
            (vertices[0][0] + vertices[2][0]) / 2,
            (vertices[0][1] + vertices[2][1]) / 2
        ])
        sierpinski_triangle(surface, color, depth - 1, vertices[1], [
            (vertices[0][0] + vertices[1][0]) / 2,
            (vertices[0][1] + vertices[1][1]) / 2
        ], [
            (vertices[1][0] + vertices[2][0]) / 2,
            (vertices[1][1] + vertices[2][1]) / 2
        ])
        sierpinski_triangle(surface, color, depth - 1, vertices[2], [
            (vertices[0][0] + vertices[2][0]) / 2,
            (vertices[0][1] + vertices[2][1]) / 2
        ], [
            (vertices[1][0] + vertices[2][0]) / 2,
            (vertices[1][1] + vertices[2][1]) / 2
        ])

# Define the main function
def main():
    # Initialize Pygame
    pygame.init()

    # Set the window size
    width, height = 800, 600
    screen = pygame.display.set_mode((width, height))

    # Set the title of the window
    pygame.display.set_caption("Sierpinski Triangle")

    # Define the colors
    white = (255, 255, 255)
    blue = (0, 0, 255)

    # Set the background color
    screen.fill(white)

    # Set the depth of recursion
    depth = 5

    # Define the vertices of the triangle
    vertices = [
        (width / 2, 100),
        (100, height - 100),
        (width - 100, height - 100)
    ]

    # Draw the Sierpinski triangle
    sierpinski_triangle(screen, blue, depth, *vertices)

    # Update the display
    pygame.display.flip()

    # Main loop
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()

# Call the main function
if __name__ == "__main__":
    main()
