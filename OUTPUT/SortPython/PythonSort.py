import time
import os

for iTest in range(1, 11):
    input_file = f"Test{iTest}.inp"
    output_file = f"Test{iTest}.out"
    
    if not os.path.exists(input_file):
        print(f"Lỗi: Không tìm thấy file {input_file}")
        continue
    
    with open(input_file, "r") as filein:
        n = int(filein.readline().strip())
        arr = list(map(float, filein.readline().split()))
    
    # Ghi nhận thời gian bắt đầu
    start = time.time()
    
    arr.sort()
    
    # Ghi nhận thời gian kết thúc
    duration = int((time.time() - start) * 1000)  # Chuyển sang milliseconds
    
    print(f"Test {iTest} {duration} ms")
    
    with open(output_file, "w") as fileout:
        fileout.write(f"{n}\n")
        fileout.write(f"{duration} ms\n")
        fileout.write(" ".join(map(str, arr)) + "\n")
