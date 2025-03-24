SUBDIRS := libft libft/io/ft_printf libft/io/get_next_line libft/DS 

define make_all_modules
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir $(1); \
	done
endef

all:
	@$(call make_all_modules, all)
	@$(MAKE) -C srcs
	@$(MAKE) -C minilibx-linux

bonus:
	@$(call make_all_modules, bonus)
	@$(MAKE) -C srcs bonus
	@$(MAKE) -C minilibx-linux

clean:
	@$(call make_all_modules, clean)
	@$(MAKE) -C srcs clean
	@$(MAKE) -C minilibx-linux

fclean:
	@$(call make_all_modules, fclean)
	@$(MAKE) -C srcs fclean

re:
	@$(call make_all_modules, re)
	@$(MAKE) -C srcs re

.PHONY: all bonus clean fclean re
