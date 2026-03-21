extends Node

@onready var check_box_1 = $ColorRect/VBoxContainer/HBoxContainer/HBoxContainer/CheckBox2
@onready var check_box_2 = $ColorRect/VBoxContainer/HBoxContainer2/CheckBox
@onready var button1 = $ColorRect/VBoxContainer/Button
@onready var text_input = $ColorRect/VBoxContainer/TextEdit
@onready var text_output1 = $ColorRect/VBoxContainer/ColorRect/Label3
@onready var text_output2 = $ColorRect/VBoxContainer/ColorRect/Label4

@onready var text_output3 = $ColorRect/VBoxContainer/ColorRect2/Label3
@onready var text_output_iter_mem = $ColorRect/VBoxContainer/ColorRect2/Label4
@onready var text_memory = $ColorRect/VBoxContainer/ColorRect/memory_label
@onready var text_memory_iteration = $ColorRect/VBoxContainer/ColorRect/memory_label2

var lab = Lab1.new()

# Called when the node enters the scene tree for the first time.
func _ready():
	print("has_method recursion1: ", lab.has_method("recursion1"))
	check_box_1.toggled.connect(_on_check_box_1_toggled)
	check_box_2.toggled.connect(_on_check_box_2_toggled)
	print(button1)
	button1.pressed.connect(_on_button1_pressed)
	check_box_1.button_pressed = true

func _on_check_box_1_toggled(button_pressed):
	if button_pressed:
		check_box_2.button_pressed = false

func _on_check_box_2_toggled(button_pressed):
	if button_pressed:
		check_box_1.button_pressed = false

func _on_button1_pressed():
	var n = int(text_input.text)
	print(lab)
	var result : RecursionResult;
	var result1 : RecursionResult;
	if(check_box_1.button_pressed == true):
		text_output2.text = "Рекурсия 12 выбрана"
		result = lab.recursion1(n);
		text_output1.text = str(result.get_value())
		text_memory.text = str(result.get_memory_amount()) + " байт"
		result1 = lab.iteration1(n);
		text_output_iter_mem.text = "memory:" + str(result1.get_memory_amount());
		text_output3.text = str(result1.get_value());
	if(check_box_2.button_pressed == true):
		text_output2.text = "Рекурсия 4 выбрана"
		result = lab.recursion2(n);
		text_output1.text = str(result.get_value())
		
		
		result1 = lab.iteration2(n);
		text_output3.text = str(result1.get_value());
		text_memory_iteration.text = str(result.get_memory_amount()) + " байт"
		text_output_iter_mem.text = "memory:" +  str(result1.get_memory_amount());
# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta: float) -> void:
	pass
