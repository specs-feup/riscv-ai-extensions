val1 = 0x784a98e3
val2 = 0xa5385e64
shift_amount = 1
perform_addition = True

# Used to check the results of pulp_vectorial_add_sub tests 37-54 and 91-108
# For cv.{op}.div2 operations use shift_amount 1, ...div4 shift_amount 2 and ...div8 shift_amount 3
# if cv.add.div use perform_addition = True, for cv.sub.div instructions use perform_addition = False

def shift(num: int, bin_length: int, shift_amount: int) -> int:
    num_string: str = ""
    
    if bin_length == 16:
        num_string = f"{num:016b}"
        if len(num_string) != 16:
            print(f"Unexpected string length: {len(num_string)} > 16")
            exit(1)
    elif bin_length == 32:
        num_string = f"{num:032b}"
        if len(num_string) != 32:
            print(f"Unexpected string length: {len(num_string)} > 32")
            exit(1)
        
        num_string = num_string[:16:]
    else:
        exit(1)
    
    fill_char = num_string[0]
    num_string = num_string[:-shift_amount:]
    num_string = fill_char*shift_amount + num_string

    if bin_length == 32:
        num_string = num_string + "0"*16
    
    return int(num_string, 2)

def perform_operation(val1: int, val2: int, perform_addition: bool):
    return val1 + val2 if perform_addition else val1 - val2
        
big_val1 = val1 & 0xffff0000
small_val1 = val1 & 0x0000ffff

big_val2 = val2 & 0xffff0000
small_val2 = val2 & 0x0000ffff

big = shift(perform_operation(big_val1, big_val2, perform_addition) & 0xffff0000, 32, shift_amount) & 0xffff0000

small = shift(perform_operation(small_val1, small_val2, perform_addition) & 0x0000ffff, 16, shift_amount)

#print(f"  big = 0x{big:08x}")
#print(f"small = 0x{small:08x}")
final = big + small

print(f"0x{final:08x}")