NAME        := ../fractol

# Compiler settings
CC          := cc
CFLAGS      := -Wall -Wextra -Werror -g -I../include -MMD -MP
LDFLAGS     := -lmlx -lXext -lX11 -lm -L../libs -lft -lftprintf

# Directories
SRCDIR      := mandatory
OBJDIR      := ../objs/srcs/mandatory

# Source files for fractol
SRCS        := color.c hooks.c init_fractal.c main.c paint_fractal.c termination.c utils.c utils_math.c hook_utils.c
OBJS        := $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
DEPS        := $(OBJS:.o=.d)  # Dependency files

all: $(NAME)

$(NAME): $(OBJS) | $(OBJDIR)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "Executable $(NAME) built successfully."

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

bonus:
	@echo "No bonus sources for fractol."

clean:
	@rm -f $(OBJS) $(DEPS)
	@echo "Object files cleaned."

fclean: clean
	@rm -f $(NAME)
	@echo "Executable cleaned."

re: fclean all

# Include dependency files if they exist
-include $(DEPS)

.PHONY: all bonus clean fclean re
