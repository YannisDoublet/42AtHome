import React, {Component} from 'react';
import {connect} from 'react-redux';
import {CSSTransition, TransitionGroup} from 'react-transition-group';
import './sign_up.css'

// Fonction pour envvoyer les values dans le prochain composant pour tout envoyer en validation au back
// et controler le form avec la validation (si non valide, ne pas update le state donc ne pas changer de composant)
// Faire le select.
// Faire le Sign-in / Forget-password etc

import SignUpForm from "./";

class SignUpStep2 extends Component {

    state = {
        mounted: false,
        formData: {
            email: {
                element: 'input',
                config: {
                    type: 'email',
                    name: 'email',
                    placeholder: 'Email'
                },
                icon: 'fas fa-envelope'
            },
            username: {
                element: 'input',
                config: {
                    type: 'text',
                    name: 'username',
                    placeholder: 'Username'
                },
                icon: 'fas fa-user'
            },
            password: {
                element: 'input',
                config: {
                    type: 'password',
                    name: 'password',
                    placeholder: 'Password'
                },
                icon: 'fas fa-lock'
            },
            check_password: {
                element: 'input',
                config: {
                    type: 'password',
                    name: 'check_password',
                    placeholder: 'Repeat password'
                },
                icon: 'fas fa-lock'
            }
        }
    };

    fetchInput = (data) => {
        const formArray = Object.keys(this.state.formData).map(key => this.state.formData[key]);
        const dataSettings = Object.keys(data).map(key => data[key]);
        return formArray.map((item, i) => {
            return (
                this.renderInput(item, dataSettings[i], i)
            );
        });
    };

    renderInput = (input, settings, i) => {
        let inputTemplate = null;
        const input_classes = [
            'sign_up_input',
            settings.touched && (settings.valid ? 'valid_input' : 'error_input')
        ].filter(v => !!v).join(' ');
        const icon_classes = [
            'input_icon',
            settings.touched && (settings.valid ? 'valid_icon' : 'error_icon')
        ].filter(v => !!v).join(' ');
        console.log(this.props);
        switch (input.element) {
            case('input'):
                inputTemplate = (
                    <CSSTransition key={i} timeout={1500} classNames="input_container" in={this.state.mounted}>
                        <div className={'input_container'}>
                            <input {...input.config} value={settings.value}
                                   className={input_classes} onChange={this.props.change}/>
                            <span className={icon_classes}>
                            <i className={input.icon}/>
                        </span>
                        </div>
                    </CSSTransition>
                );
                break;
            case('select'):
                inputTemplate = (
                    <CSSTransition key={i} timeout={1500} classNames="sign_up_select" in={this.state.mounted}>
                        <select className={'sign_up_select'}>
                            <option hidden selected>{input.name}</option>
                            {input.options ? input.options.map(item => (
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
        const settings = this.props;
        return (
            <div className={'sign_up_container'}>
                {this.fetchInput(settings.data)}
                <div className={'button_container'}>
                    <CSSTransition timeout={1500} classNames="sign_up_button" in={this.state.mounted}>
                        <button className={'sign_up_button'}
                                onClick={() => this.props.handleStage(settings.stage)}>
                            Back
                        </button>
                    </CSSTransition>
                    <CSSTransition timeout={1500} classNames="sign_up_button" in={this.state.mounted}>
                        <button className={'sign_up_button'}
                                onClick={() => this.props.submit}>
                            Submit
                        </button>
                    </CSSTransition>
                </div>
            </div>
        );
    }
}

function mapStateToProps(state) {
    return {};
}

export default connect(mapStateToProps)(SignUpStep2);

