import psutil
print(f"CPU: {psutil.cpu_count()}")
print(f"RAM: {psutil.virtual_memory()[0]//1024} kb")
