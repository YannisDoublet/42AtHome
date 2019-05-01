import React, {Component} from 'react'
import {CSSTransition} from "react-transition-group"

class SignUpStep1 extends Component {

    state = {
        mounted: false,
        formData: {
            firstname: {
                element: 'input',
                config: {
                    type: 'text',
                    name: 'firstname',
                    placeholder: 'Firstname',
                },
                icon: 'fas fa-id-badge'
            },
            lastname: {
                element: 'input',
                config: {
                    type: 'text',
                    name: 'lastname',
                    placeholder: 'Lastname',
                },
                icon: 'fas fa-address-card'
            },
            age: {
                element: 'input',
                config: {
                    type: 'text',
                    name: 'age',
                    placeholder: 'Age',
                },
                icon: 'fas fa-birthday-cake'
            },
            gender: {
                element: 'select',
                type: 'select',
                name: 'Gender',
                options: [
                    'Man',
                    'Woman',
                    'Undefined'
                ]
            },
            sexuality: {
                element: 'select',
                type: 'select',
                name: 'Sexuality',
                options: [
                    'Heterosexual',
                    'Bisexual',
                    'Homosexual'
                ]
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

    validation = (newState, name) => {
        console.log(this.props);
        if (name === 'firstname' || name === 'lastname') {
            if (parseInt(newState[name].value.length) === 0) {
                newState[name].valid = false;
                this.props.showError(name.charAt(0).toUpperCase() + name.slice(1) + ' should not be empty !');
            }
            else if (!newState[name].value.match('^[a-zA-Z]+(([\',. -][a-zA-Z ])?[a-zA-Z]*)*$')) {
                newState[name].valid = false;
                this.props.showError(name.charAt(0).toUpperCase() + name.slice(1) + ' should only contain letters !');
            } else {
                this.props.showError();
                newState[name].valid = true;
            }
        } else if (name === 'age') {
            if (parseInt(newState[name].value.length) === 0) {
                newState[name].valid = false;
                this.props.showError(name.charAt(0).toUpperCase() + name.slice(1) + ' should not be empty !');
            } else if (!newState[name].value.match('^[0-9]+$')) {
                newState[name].valid = false;
                this.props.showError(name.charAt(0).toUpperCase() + name.slice(1) + ' should only contain numbers !');
            } else if (parseInt(newState[name].value) < 18) {
                newState[name].valid = false;
                this.props.showError('You need to be adult to register !');
            } else if (parseInt(newState[name].value.length) >= 3) {
                newState[name].valid = false;
                this.props.showError(name.charAt(0).toUpperCase() + name.slice(1) + ' need to be between 18 and 99 !');
            } else {
                this.props.showError();
                newState[name].valid = true;
            }
        }
        this.props.change(newState);
    };

    handleChange = (evt, name) => {
        let newState = this.props.data;
        newState[name].value = evt.target.value;
        newState[name].touched = true;
        this.validation(newState, name);
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
                                   className={input_classes}
                                   onChange={(evt) => this.handleChange(evt, input.config.name)}/>
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
            <div>
                <div className={'sign_up_container'}>
                    {this.fetchInput(settings.data)}
                    <div className={'button_container'}>
                        <CSSTransition timeout={1500} classNames="sign_up_button" in={this.state.mounted}>
                            <button className={'sign_up_button'}
                                    onClick={() => this.props.handleStage(settings.stage)}>
                                Continue
                            </button>
                        </CSSTransition>
                    </div>
                </div>
            </div>
        );
    }
}

export default SignUpStep1;