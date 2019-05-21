import random;

def binary_search(ele_list, search_ele):
    
    print("binary_search++")
    
    low_idx = 0;
    high_idx = len(ele_list) - 1;
    
    while(low_idx <= high_idx):
        print("low_idx:{}, high_idx:{}".format(low_idx,high_idx));
        mid = int(low_idx + (high_idx - low_idx)/2);
        if(ele_list[mid] == search_ele):
            search_ele_idx=mid;
            break;
        elif(search_ele < ele_list[mid]):
            high_idx = mid-1;
        elif(search_ele > ele_list[mid]):
            low_idx = mid+1;
        else:
            print("Error searching element")

    if(low_idx > high_idx):
        return -1;
    else:
        return search_ele_idx;
    print("binary_search--")

def main():
    print ("main++")
    ele_list = [random.randrange(1,101,1) for _ in range(10)]
    ele_list.sort();
    print("Elmement list: {}".format(ele_list));
    print("Elmement idx: {}".format(binary_search(ele_list, 5)));
    print ("main--")
    
if __name__ == "__main__":
    main()
