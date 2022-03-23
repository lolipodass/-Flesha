import React from "react";
import './JobMenu.css'

class JobMenu extends React.Component {


    change(Event) {
        this.setState({ value: Event.target.value });
    }
    obj = {
        first: ["coc.ru", "2.ru", "jojo.com", "gucci.gang", "bang.bang", "jojo", "belstu.best"],
        second: ["rocket.ru", "leack.com", "foster.bolt", "dock.dock", "cheeck.cho", "jojo.com", "belstu.best"],
        three: ["gardon.cu", "qq.all", "bb.all", "src.joj", "gad.on", "barcov.ski", "jola.ro", "belstu.best"],
        four: ["manga.ru", "xyx.jp", "jo.pa", "co.ck", "idk.dot", "belstu.best"],
    };


    render() {
        return (
            <div>
                Выбери профессию
                <select value={this.state.value} onChange={this.change}>
                    <option value="first">профессия 1</option>
                    <option value="second">профессия 2</option>
                    <option value="three">профессия 3</option>
                    <option value="four">профессия 4</option>
                </select>

                <ul>
                    <li><a href={this.obj[this.state.value][0]}>1 link {this.state.value}</a></li>
                    <li><a href={this.obj[this.state.value][1]}>2 link</a></li>
                    <li><a href={this.obj[this.state.value][2]}>3 link</a></li>
                    <li><a href={this.obj[this.state.value][3]}>4 link</a></li>
                    <li><a href={this.obj[this.state.value][4]}>5 link</a></li>
                    <li><a href={this.obj[this.state.value][5]}>6 link</a></li>
                    <li><a href={this.obj[this.state.value][6]}>6 link</a></li>
                </ul>
            </div>
        );
    }
    constructor(props) {
        super(props);
        this.state = { value: "first" };

        this.change = this.change.bind(this);
    }

}

export default JobMenu;

// !Создайте компонент меню JobMenu с полезными ссылками для различных профессий. Реализуйте функционал выбора профессии на ваше усмотрение (список/чекбоксы/радиокнопки).

// !Выбор профессии и меню должны быть реализованы отдельными компонентами. В зависимости от выбранной профессии в первом компоненте, должен изменяться компонент меню.

//! Минимальное количество профессий - 5, минимальное количество пунктов меню - 7.