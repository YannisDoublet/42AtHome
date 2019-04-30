import React, {Component} from 'react';
import {connect} from 'react-redux';
import {CSSTransition, TransitionGroup} from 'react-transition-group';
import './sign_up.css'

// Fonction pour envvoyer les values dans le prochain composant pour tout envoyer en validation au back
// et controler le form avec la validation (si non valide, ne pas update le state donc ne pas changer de composant)
// Faire le select.
// Faire le Sign-in / Forget-password etc

import SignUpForm_2 from "./sign_up_2";

class SignUpForm extends Component {

    state = {
        stage: 1,
        mounted: false,
        formData: {
            name: {
                element: 'input',
                config: {
                    type: 'text',
                    name: 'firstname',
                    placeholder: 'Firstname',
                    required: true
                },
                value: '',
                touched: true,
                valid: false,
                icon: 'fas fa-id-badge',
                stage: 1
            },
            lastname: {
                element: 'input',
                config: {
                    type: 'text',
                    name: 'lastname',
                    placeholder: 'Lastname',
                    required: true
                },
                value: '',
                touched: false,
                valid: true,
                icon: 'fas fa-address-card',
                stage: 1
            },
            age: {
                element: 'input',
                config: {
                    type: 'text',
                    name: 'age',
                    placeholder: 'Age',
                    required: true
                },
                value: '',
                touched: false,
                valid: false,
                icon: 'fas fa-birthday-cake',
                stage: 1
            },
            gender: {
                element: 'select',
                type: 'select',
                name: 'Gender',
                options: [
                    'Man',
                    'Woman',
                    'Undefined'
                ],
                required: true,
                touched: false,
                valid: true,
                stage: 1
            },
            sexuality: {
                element: 'select',
                type: 'select',
                name: 'Sexuality',
                options: [
                    'Heterosexual',
                    'Bisexual',
                    'Homosexual'
                ],
                touched: false,
                valid: true,
                stage: 1
            },
            button: {
                element: 'button',
                value: 'Continue',
                stage: 1
            },
            email: {
                element: 'input',
                config: {
                    type: 'email',
                    name: 'email',
                    placeholder: 'Email',
                    required: true
                },
                value: '',
                touched: false,
                valid: true,
                stage: 2
            },
            username: {
                element: 'input',
                config: {
                    type: 'text',
                    name: 'username',
                    placeholder: 'Username',
                    required: true
                },
                value: '',
                touched: false,
                valid: true,
                stage: 2
            },
            password: {
                element: 'input',
                config: {
                    type: 'password',
                    name: 'password',
                    placeholder: 'Password',
                    required: true
                },
                value: '',
                touched: false,
                valid: true,
                stage: 2
            },
            check_password: {
                element: 'input',
                config: {
                    type: 'password',
                    name: 'check',
                    placeholder: 'Password again',
                    required: true
                },
                value: '',
                touched: false,
                valid: true,
                stage: 2
            }
        }
    };

    fetchStageInput = (stage) => {
        if (stage === 1 || stage === 2) {
            const formArray = [];
            for (let element in this.state.formData) {
                if (stage === this.state.formData[element].stage) {
                    formArray.push({element: this.state.formData[element]});
                }
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
        console.log(this.state.mounted);
        const stage = this.state.stage;
        return (
            <div className={'sign_up_container'}>
                {stage === 1 ?
                    <div className={'sign_up_container'}>{this.fetchStageInput(stage)}
                        <div className={'button_container'}>
                            <CSSTransition timeout={1500} classNames="sign_up_button" in={this.state.mounted}>
                                <button className={'sign_up_button'}
                                        onClick={() => this.setState({stage: this.state.stage + 1})}>
                                    Continue
                                </button>
                            </CSSTransition>
                        </div>
                    </div> : <SignUpForm_2/>}
            </div>
        );
    }
}

function mapStateToProps(state) {
    return {};
}

export default connect(mapStateToProps)(SignUpForm);
