from joblib import load

data = load('/home/kemove/vscode_workspace/LeetcodePracticeC++/res/nuscenes_infos_temporal_train.pkl')
# print(data[2])  # 访问第3行
print(type(data))

# 如果是列表，直接访问索引即可
# print(data[2]['infos'])
# 检查数据类型，确保它是一个字典
if isinstance(data, dict):
    # 打印所有键
    print(data.keys())
else:
    print("The file does not contain a dictionary.")
    
print(data['infos'])