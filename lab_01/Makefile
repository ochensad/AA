СС := g++
CFLAGS := -Wall -Werror -Wextra -Wpedantic -I./inc

# Получение переменных с файлами

SRC_DIR := ./src
CFILES := $(wildcard $(SRC_DIR)/*.cpp)

INC_DIR := ./inc
INCLUDEFILES := $(wildcard $(INC_DIR)/*.h)

OUT_DIR := ./out
OBJFILES := $(CFILES:$(SRC_DIR)/%.cpp=$(OUT_DIR)/%.o)


# Функции
app.exe : $(OUT_DIR) $(OBJFILES)
	g++ $(OBJFILES) -o $@

$(OUT_DIR):
	@mkdir -p $@

$(OUT_DIR)/%.o : $(SRC_DIR)/%.cpp $(INCLUDE_FILES)
	g++ $(CFLAGS) -c $< -o $@


.PHONY : clean func unit flag

clean:
	$(RM) *.o *.exe -rf $(OUT_DIR)

run: app.exe
	./app.exe