function lab1() {
    alert('Вас приветствует учебный центр');

    x = prompt('Введите имя');
    if (x == null) {
        document.write( < p style = "color: #1212;" > "УХОДИ" < /p>)
        }
        else {
            alert("Добро пожаловать на наши курсы, " + x);

            if (confirm("Хотите стать Web-дизайнером?")) {
                alert("Учите стили CSS")
            } else {
                alert("Упускаете время!")
            }
        }

        function lab2() {
            num1 = 12;
            num2 = 14;
            char1 = "88";
            char2 = "99";
            answer1 = num1 + num2;
            answer2 = char1 + char2;
            answer3 = char1 + num1;
            answer4 = num2 + char2;
            alert("начальные данные" + "\n" + "число1: " + num1 + "\n" + "число2: " + num2 + "\n" + "строка1: " + char1 + "\n" + "строка2: " + char2 + ";")
            alert("число1 + число2: " + answer1 + "\n" + "строка1+строка2:" + answer2 + "\n" + "строка1 + число1: " + answer3 + "\n" + "число2 + строка2: " + answer4);
            alert("Результат сложения строки и числа всегда будет строка");
        }

        function lab3() {
            let x = 12;
            y = 2;
            z = (35 * x - 25 * y) / 5 + 232;
            d = 8 * y + 6 / x + 5 * x + 1 / y + 6 * 3;
            alert(z);
            alert(d);
            g = z % d;
            alert(g);
            document.write(z + " " + d + " " + g);
        }

        function lab4() {
            x = prompt('Введите любое число: ', 'Число')
            if (x == null) {
                document.write("Ты куда лезешь")
            } else if ((x < 20 || x > 40) && x != 15 && x % 5 == 0) {
                alert("Правильное значение")
            } else {
                alert("Не правильное значение")
            }
        }

        function lab5() {

            a = Number(prompt("Введите первое число "))
            b = Number(prompt("Введите второе число "))

            //alert(a+b)
            if (a > b) {
                alert("Число " + a + " больше числа " + b)
            } else if (a == b) {
                alert("Число " + a + " равняется числу " + b)
            } else {
                alert("Число " + a + " меньше числа " + b)
            }
            a > 0 ? a = 10 : a = -3;
            alert("Число " + a);
        }

        function lab6() {
            date = new Date();
            x = date.getDay();
            switch (x) {
                case 0:
                    alert("Воскресенье")
                    document.write("Воскресенье")
                    break;
                case 1:
                    alert("Понедельник")
                    document.write("Понедельник")
                    break;
                case 2:
                    alert("Вторник")
                    document.write("Вторник")
                    break;
                case 3:
                    alert("Среда")
                    document.write("Среда")
                    break;
                case 4:
                    alert("Четверг")
                    document.write("Четверг")
                    break;
                case 5:
                    alert("Пятница")
                    document.write("Пятница")
                    break;
                case 6:
                    alert("Суббота")
                    document.write("Суббота")
                    break;
                default:
                    alert("Амм, НУммм, как бы дааааааа")
                    document.write("¯\_( ͡° ͜ʖ ͡°)_/¯")
            }
        }

        function lab7() {

            try {
                x = prompt('Введите имя');
                if (x == null) {
                    document.write("УХОДИ")
                    throw false;
                } else
                    alert('да');
            } catch {
                alert('Ошибка ');
            }
        }