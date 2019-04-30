import React, {Component} from 'react';
import {connect} from 'react-redux';
import {CSSTransition, TransitionGroup} from 'react-transition-group';
import './sign_up.css'

// Fonction pour envvoyer les values dans le prochain composant pour tout envoyer en validation au back
// et controler le form avec la validation (si non valide, ne pas update le state donc ne pas changer de composant)
// Faire le select.
// Faire le Sign-in / Forget-password etc

import SignUpForm from "./";

class SignUpForm_2 extends Component {

    state = {
        stage: 2,
        mounted: false,
        formData: {
            email: {
                element: 'input',
                config: {
                    type: 'email',
                    name: 'email',
                    placeholder: 'Email',
                    required: true
                },
                icon: 'fas fa-envelope',
                value: '',
                touched: false,
                valid: true
            },
            username: {
                element: 'input',
                config: {
                    type: 'text',
                    name: 'username',
                    placeholder: 'Username',
                    required: true
                },
                icon: 'fas fa-user',
                value: '',
                touched: false,
                valid: true
            },
            password: {
                element: 'input',
                config: {
                    type: 'password',
                    name: 'password',
                    placeholder: 'Password',
                    required: true
                },
                icon: 'fas fa-lock',
                value: '',
                touched: false,
                valid: true
            },
            check_password: {
                element: 'input',
                config: {
                    type: 'password',
                    name: 'check',
                    placeholder: 'Repeat password',
                    required: true
                },
                icon: 'fas fa-lock',
                value: '',
                touched: false,
                valid: true
            },
            back_button: {
                element: 'button',
                value: 'Back',
                cb: 'this.setState({stage: this.state.stage - 1})'
            }
        }
    };

    fetchStageInput = (stage) => {
        if (stage === 1 || stage === 2) {
            const formArray = [];
            for (let element in this.state.formData) {
                formArray.push({element: this.state.formData[element]});
            }
            console.log(formArray);
            return formArray.map((item, i) => {
                return (
                    this.renderInput(item, i)
                )
            })
        }
    };

    renderInput = (data, i) => {
        let inputTemplate = null;
        const input_classes = [
            'sign_up_input',
            data.element.touched && (data.element.valid ? 'valid_input' : 'error_input')
        ].filter(v => !!v).join(' ');
        const icon_classes = [
            'input_icon',
            data.element.touched && (data.element.valid ? 'valid_icon' : 'error_icon')
        ].filter(v => !!v).join(' ');
        switch (data.element.element) {
            case('input'):
                inputTemplate = (
                    <CSSTransition key={i} timeout={1500} classNames="input_container" in={this.state.mounted}>
                        <div className={'input_container'}>
                            <input {...data.element.config} value={data.element.value}
                                   className={input_classes}/>
                            <span className={icon_classes}>
                            <i className={data.element.icon}/>
                        </span>
                        </div>
                    </CSSTransition>
                );
                break;
            case('select'):
                inputTemplate = (
                    <CSSTransition key={i} timeout={1500} classNames="sign_up_select" in={this.state.mounted}>
                        <select className={'sign_up_select'}>
                            <option hidden selected>{data.element.name}</option>
                            {data.element.options ? data.element.options.map(item => (
                                <option>{item}</option>
                            )) : null}
                        </select>
                    </CSSTransition>);
                break;
            // case('button'):
            //     inputTemplate = (
            //         <CSSTransition key={i} timeout={1500} classNames="sign_up_button" in={this.state.mounted}>
            //             <button className={'sign_up_button'}
            //                     onClick={() => this.setState({stage: this.state.stage - 1})}>
            //                 {data.element.value}
            //             </button>
            //         </CSSTransition>);
            //     break;
            default:
                inputTemplate = null;
                break;
        }
        return inputTemplate;
    };

    componentDidMount() {
        this.setState({
            mounted: true
        })
    }

    render() {
        const stage = this.state.stage;
        return (
            <div className={'sign_up_container'}>
                {stage === 2 ? <div>{this.fetchStageInput(stage)}
                    <div className={'button_container'}>
                        <CSSTransition timeout={1500} classNames="sign_up_button" in={this.state.mounted}>
                            <button className={'sign_up_button'}
                                    onClick={() => this.setState({stage: this.state.stage - 1})}>
                                Back
                            </button>
                        </CSSTransition>
                        <CSSTransition timeout={1500} classNames="sign_up_button" in={this.state.mounted}>
                            <button className={'sign_up_button'}
                                    onClick={() => this.setState({stage: this.state.stage - 1})}>
                                Submit
                            </button>
                        </CSSTransition>
                    </div>
                </div> : <SignUpForm/>}
            </div>
        );
    }
}

function mapStateToProps(state) {
    return {};
}

export default connect(mapStateToProps)(SignUpForm_2);

