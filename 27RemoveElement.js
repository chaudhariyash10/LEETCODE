var removeElement = function (nums, val) {
    
           var n = 0 ;
           
           for(let i = 0  ; i < nums.length ; i++){
               if(nums[i] === val ) {
                   continue;
               }

               nums[n++] = nums[i];
           }

           return n;
    
};

console.log(removeElement([2,3,3] , 3));