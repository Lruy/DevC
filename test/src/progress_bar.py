import os
import time

# 获取终端宽度，预留百分比显示的空间（10个字符）
width = os.get_terminal_size().columns - 10
# 生成豆子背景字符串
all_beans = (" o " * (width // 3 + 1))[:width]

# 遍历进度条的每一个位置，模拟进度从0%到100%
for i in range(len(all_beans)):
    # 计算当前进度百分比（保留整数）
    progress_percent = int((i + 1) / len(all_beans) * 100)
    
    # 构建进度条：-填充已完成部分 + c（吃豆人） + 剩余豆子
    bar = '-' * i + ('c' if i != len(all_beans) - 1 else "-") + all_beans[i+1:]
    
    # 输出进度条+百分比，\r回到行首覆盖，end=""不换行，flush强制刷新
    print(f"\r{bar} {progress_percent}%", end="", flush=True)
    
    # 控制动画速度
    time.sleep(0.05)

# 进度完成后换行，避免后续输出和进度条重叠
print()