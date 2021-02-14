class Solution {
  public:
    ListNode * mid(ListNode * start, ListNode * end) {
      ListNode * fast = start;

      ListNode * slow = start;

      while (fast != end && fast -> next != end) {
        fast = fast -> next -> next;
        slow = slow -> next;
      }

      return slow;
    }

  ListNode * merge(ListNode * left, ListNode * right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    ListNode * head = NULL, * iter = NULL;

    if (left -> val > right -> val) {
      head = right;
      iter = head;
      right = right -> next;
    } else {
      head = left;
      iter = head;
      left = left -> next;

    }
    while (left != NULL && right != NULL) {
      if (left -> val < right -> val) {
        iter -> next = left;
        left = left -> next;
        iter = iter -> next;
      } else {
        iter -> next = right;
        right = right -> next;
        iter = iter -> next;
      }
    }
    if (left != NULL) iter -> next = left;
    if (right != NULL) iter -> next = right;
    return head;

  }
  ListNode * mergeSort(ListNode * start, ListNode * end) {
    if (start == end) return start;
    if (start == NULL) return NULL;
    ListNode * middle = mid(start, end);
    ListNode * right = mergeSort(middle -> next, end);
    middle -> next = NULL;
    ListNode * left = mergeSort(start, middle);
    return merge(left, right);

  }
  ListNode * sortList(ListNode * head) {

    if (head == NULL) return head;

    ListNode * end = head;
    while (end -> next != NULL) {
      end = end -> next;
    }

    return mergeSort(head, end);

  }
};
