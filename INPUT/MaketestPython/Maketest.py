import random
import os

# Tạo 10 file input
for iTest in range(1, 11):
    output_file = f"Test{iTest}.inp"
    
    try:
        with open(output_file, "w") as fileout:
            n = int(1e6)
            fileout.write(f"{n}\n")
            
            arr = [random.uniform(-1e6, 1e6) for _ in range(n)]
            
            if iTest == 1:
                arr.sort()
            elif iTest == 2:
                arr.sort(reverse=True)
            
            fileout.write(" ".join(map(str, arr)) + "\n")
        print(f"Đã tạo tệp {output_file}")
    except Exception as e:
        print(f"Lỗi khi tạo tệp {output_file}: {e}")

print("Danh sách tệp trong thư mục:", os.listdir())
