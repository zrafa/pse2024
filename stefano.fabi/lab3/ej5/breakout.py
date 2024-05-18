import pygame
import random

# Inicializar Pygame
pygame.init()

# Dimensiones de la pantalla
SCREEN_WIDTH = 800
SCREEN_HEIGHT = 600

# Colores
WHITE = (255, 255, 255)
BLUE = (0, 0, 255)
RED = (255, 0, 0)
GREEN = (0, 255, 0)

# Tamaño de los bloques
BLOCK_WIDTH = 60
BLOCK_HEIGHT = 20

# Crear la pantalla
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption("Breakout")

# Definir la paleta del jugador
player_width = 100
player_height = 20
player = pygame.Rect(350, 580, player_width, player_height)

# Definir la pelota
ball_radius = 10
ball = pygame.Rect(395, 565, ball_radius * 2, ball_radius * 2)
ball_speed_x = 3
ball_speed_y = -3

# Crear los bloques
blocks = []
for row in range(5):
    for col in range(10):
        block = pygame.Rect(75 + col * (BLOCK_WIDTH + 10), 50 + row * (BLOCK_HEIGHT + 10), BLOCK_WIDTH, BLOCK_HEIGHT)
        blocks.append(block)

# Puntuación del jugador
score = 0

# Estado del juego
game_over = False

# Bucle principal del juego
running = True
while running:
    # Manejar eventos
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    if not game_over:
        # Mover la paleta del jugador
        keys = pygame.key.get_pressed()
        if keys[pygame.K_a] or keys[pygame.K_LEFT]:
            player.x -= 5
        if keys[pygame.K_d] or keys[pygame.K_RIGHT]:
            player.x += 5

        # Mover la pelota
        ball.x += ball_speed_x
        ball.y += ball_speed_y

        # Colisiones con los bordes de la pantalla
        if ball.left <= 0 or ball.right >= SCREEN_WIDTH:
            ball_speed_x *= -1
        if ball.top <= 0:
            ball_speed_y *= -1

        # Colisión con la paleta del jugador
        if ball.colliderect(player):
            ball_speed_y *= -1

        # Colisión con los bloques
        for block in blocks[:]:
            if ball.colliderect(block):
                blocks.remove(block)
                ball_speed_y *= -1
                score += 10

        # Si la pelota cae fuera de la pantalla, el juego termina
        if ball.top >= SCREEN_HEIGHT:
            game_over = True

        # Si todos los bloques han sido destruidos, el jugador gana
        if len(blocks) == 0:
            game_over = True

    else:
        # Si el juego ha terminado, mostrar un mensaje de victoria o derrota y la puntuación
        font = pygame.font.SysFont(None, 48)
        if len(blocks) == 0:
            text = font.render("You Win! Score: {}".format(score), True, GREEN)
        else:
            text = font.render("Game Over! Score: {}".format(score), True, RED)
        text_rect = text.get_rect(center=(SCREEN_WIDTH // 2, SCREEN_HEIGHT // 2))
        screen.blit(text, text_rect)
        pygame.display.flip()

        # Reiniciar el juego si se presiona una tecla
        keys = pygame.key.get_pressed()
        if any(keys):
            game_over = False
            # Restablecer la posición de la paleta y la pelota
            player.x = 350
            ball.x = 395
            ball.y = 565
            ball_speed_x = random.choice([-3, 3])
            ball_speed_y = -3
            # Restablecer los bloques
            blocks = []
            for row in range(5):
                for col in range(10):
                    block = pygame.Rect(75 + col * (BLOCK_WIDTH + 10), 50 + row * (BLOCK_HEIGHT + 10), BLOCK_WIDTH, BLOCK_HEIGHT)
                    blocks.append(block)
            # Restablecer la puntuación
            score = 0

    # Dibujar elementos en la pantalla
    screen.fill(WHITE)
    pygame.draw.rect(screen, BLUE, player)
    pygame.draw.circle(screen, RED, ball.center, ball_radius)
    for block in blocks:
        pygame.draw.rect(screen, GREEN, block)
    # Mostrar la puntuación
    font = pygame.font.SysFont(None, 30)
    score_text = font.render("Score: {}".format(score), True, BLUE)
    screen.blit(score_text, (10, 10))
    pygame.display.flip()

    # Controlar la velocidad de fotogramas
    pygame.time.Clock().tick(60)

pygame.quit()
