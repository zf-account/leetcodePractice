# 快速排序链表
# 时间复杂度：O(nlogn)
# 空间复杂度：O(1)

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def print_list(head):
    current = head
    values = []
    while current:
        values.append(str(current.val))
        current = current.next
    print(" -> ".join(values) if values else "空链表")

def quick_sort_list(head):
    if not head or not head.next:
        return head
    
    # 选择头节点作为基准值
    pivot = head.val
    
    # 分割链表
    less_head = less_tail = None
    equal_head = equal_tail = None
    greater_head = greater_tail = None
    
    current = head
    while current:
        next_node = current.next
        current.next = None  # 断开当前节点
        
        if current.val < pivot:
            # 小于基准值的节点
            if not less_head:
                less_head = less_tail = current
            else:
                less_tail.next = current
                less_tail = current
        elif current.val == pivot:
            # 等于基准值的节点
            if not equal_head:
                equal_head = equal_tail = current
            else:
                equal_tail.next = current
                equal_tail = current
        else:
            # 大于基准值的节点
            if not greater_head:
                greater_head = greater_tail = current
            else:
                greater_tail.next = current
                greater_tail = current
        
        current = next_node
    
    # 递归排序小于和大于基准值的部分
    sorted_less = quick_sort_list(less_head)
    sorted_greater = quick_sort_list(greater_head)
    
    # 合并三个部分
    result_head = result_tail = None
    
    # 添加小于基准值的部分
    if sorted_less:
        result_head = sorted_less
        result_tail = sorted_less
        while result_tail.next:
            result_tail = result_tail.next
    
    # 添加等于基准值的部分
    if equal_head:
        if not result_head:
            result_head = equal_head
        else:
            result_tail.next = equal_head
        result_tail = equal_tail
    
    # 添加大于基准值的部分
    if sorted_greater:
        if not result_head:
            result_head = sorted_greater
        else:
            result_tail.next = sorted_greater
    
    return result_head

def create_list_from_array(arr):
    """从数组创建链表"""
    if not arr:
        return None
    
    head = ListNode(arr[0])
    current = head
    for val in arr[1:]:
        current.next = ListNode(val)
        current = current.next
    
    return head

def list_to_array(head):
    """将链表转换为数组"""
    arr = []
    current = head
    while current:
        arr.append(current.val)
        current = current.next
    return arr

# 测试代码
if __name__ == "__main__":
    # 测试用例1：普通数组
    test_cases = [
        [4, 2, 1, 3],
        [1, 1, 1, 1],
        [5, 4, 3, 2, 1],
        [1, 2, 3, 4, 5],
        [3, 1, 4, 1, 5, 9, 2, 6],
        []
    ]
    
    for i, test_case in enumerate(test_cases):
        print(f"\n测试用例 {i+1}: {test_case}")
        
        # 创建链表
        head = create_list_from_array(test_case)
        print("原始链表:", end=" ")
        print_list(head)
        
        # 排序
        sorted_head = quick_sort_list(head)
        print("排序后链表:", end=" ")
        print_list(sorted_head)
        
        # 验证结果
        sorted_array = list_to_array(sorted_head)
        expected = sorted(test_case)
        print(f"排序结果: {sorted_array}")
        print(f"期望结果: {expected}")
        print(f"排序正确: {sorted_array == expected}")
