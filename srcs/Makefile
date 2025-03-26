NAME        := ../fractol

# Compiler settings
CC          := cc
CFLAGS      := -Wall -Wextra -Werror -I../include
LDFLAGS     := -lmlx -lXext -lX11 -lm -L../libs -lft -lftprintf

# Directories
OBJDIR      := ../objs/srcs/

# Source files for fractol (located in the current directory)
SRCS        := color.c hooks.c init_fractal.c main.c paint_fractal.c termination.c utils.c utils_math.c hook_utils.c hook_utils2.c init_fractal_utils.c
OBJS        := $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
DEPS        := $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS) | $(OBJDIR)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "Executable $(NAME) built successfully."

# Build object files from the current directory
$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

bonus: all

clean:
	@rm -f $(OBJS) $(DEPS)
	@echo "Object files cleaned."

fclean: clean
	@rm -f $(NAME)
	@echo "Executable cleaned."

re: fclean all

-include $(DEPS)

.PHONY: all bonus clean fclean re

