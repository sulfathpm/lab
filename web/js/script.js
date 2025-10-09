 function oddEven() {
            const numberInput = document.getElementById('number');
            const num = Number(numberInput.value);

            if(num%2==0){
                document.writeln(num+' is even')
            }else{
                alert(num+' is odd')
            }
        }