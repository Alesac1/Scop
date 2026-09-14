NAME        := scop

CXX         := c++
CXXFLAGS    := -Wall -Wextra -Werror -std=c++17
INCLUDES    := -Iinclude

SRC_DIR     := src
OBJ_DIR     := obj

SRCS        := $(SRC_DIR)/main.cpp \
               $(SRC_DIR)/App.cpp

OBJS        := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

LIBS        := -lglfw -lGL -ldl -lpthread

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(LIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re